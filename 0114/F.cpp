#include<bits/stdc++.h>
using namespace std;

struct node {
    long long l, r;
    long long c;
    long long cnt;
    long long lf, rf;
} tree[200050 <<2];

struct line {
    long long lf, y, rf;
    long long d;
} scan[200050];

long long x[200050];

bool cmp(line l1, line l2) {
    return l1.y < l2.y;
}

void build(long long i, long long s, long long e) {
    tree[i].l = s;
    tree[i].r = e;
    tree[i].lf = x[s];
    tree[i].rf = x[e];
    tree[i].c = tree[i].cnt = 0;
    if (s + 1 == e) return;
    long long mid = (s + e) >> 1;
    build(i << 1, s, mid);
    build(i << 1 | 1, mid, e);
}

void calen(long long i) {
    if (tree[i].c > 0) {
        tree[i].cnt = tree[i].rf - tree[i].lf;
        return;
    }
    if (tree[i].r - tree[i].l == 1) tree[i].cnt = 0;
    else tree[i].cnt = tree[i << 1].cnt + tree[i << 1 | 1].cnt;
}

void updata(long long i, line l) {
    if (tree[i].lf >= l.lf && tree[i].rf <= l.rf) {
        tree[i].c += l.d;
        calen(i);
        return;
    }
    if (tree[i].lf >= l.rf || tree[i].rf <= l.lf) return;
    updata(i << 1, l);
    updata(i << 1 | 1, l);
    calen(i);
}

int main() {
    long long n, i, j, icase = 0;
    long long x1, y1, x2, y2;
    scanf("%lld", &n);
    for (i = 0; i < n; ++i) {
        scanf("%lld%lld%lld", &x1, &x2, &y2);
        y1 = 0;
        scan[2 * i].lf = x1;
        scan[2 * i].rf = x2;
        scan[2 * i].y = y1;
        scan[2 * i].d = 1;
        scan[2 * i + 1].lf = x1;
        scan[2 * i + 1].rf = x2;
        scan[2 * i + 1].y = y2;
        scan[2 * i + 1].d = -1;
        x[2 * i] = x1;
        x[2 * i + 1] = x2;
    }
    sort(x, x + 2 * n);
    sort(scan, scan + 2 * n, cmp);
    build(1, 0, 2 * n - 1);
    updata(1, scan[0]);
    long long res = 0;
    for (i = 1; i < 2 * n; ++i) {
        res += (scan[i].y - scan[i - 1].y) * tree[1].cnt;
        updata(1, scan[i]);
    }
    printf("%lld\n", res);
}

