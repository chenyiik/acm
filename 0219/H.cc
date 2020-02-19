#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int maxn = int(2e5) + 5;
int a[maxn];
struct P { int high, index; } b[maxn];
bool cmp(P a, P b) { return a.high == b.high ? a.index < b.index : a.high < b.high; }

struct node{ int L,R; P ma,mi; }tree[maxn<<2];
void build(int L,int R,int p);
P query_max(int L,int R,int p);
P query_min(int L,int R,int p);

int main()
{
	int n, k; scanf("%d%d", &n, &k);
	for (int i = 1; i <= n + 1; i++)
		scanf("%d", &a[i]), b[i] = {a[i], i};
	sort(b + 1, b + n + 2, cmp);
	build(1, n + 1, 1);
	while (k--)
	{
		double g; scanf("%lf", &g);
		double ans = 0; bool flag = false;
		// if (g >= 0)
		for (int l = 1, r = 1; l <= n + 1; l++)
		{
			while (r <= n + 1 && b[r].high - b[l].high < g) r++;
			if (r > n + 1) break;
			P L = b[l];
			P R = query_max(r, n + 1, 1);
			double dist = R.index - L.index;
			if (dist < 0) continue;

		}
		if (flag)
			printf("%f\n", ans);
		else
			puts("-1");
	}
	return 0;
}

void up(int p){
    if(tree[p<<1].ma.index>tree[p<<1|1].ma.index)
        tree[p].ma=tree[p<<1].ma;
    else
        tree[p].ma=tree[p<<1|1].ma ;
    if(tree[p<<1].mi.index<tree[p<<1|1].mi.index)
        tree[p].mi=tree[p<<1].mi;
    else
        tree[p].mi=tree[p<<1|1].mi;
}
void build(int L,int R,int p){
    tree[p].L=L;
    tree[p].R=R;
    if(L==R){
        tree[p].ma=tree[p].mi=b[L];
        return;
    }
    int mid=(L+R)>>1;
    build(L,mid,p<<1);
    build(mid+1,R,p<<1|1);
    up(p);
}
P query_max(int L,int R,int p){
    if(tree[p].L==L&&tree[p].R==R)
        return tree[p].ma;
    int mid=(tree[p].L+tree[p].R)>>1;
    if(R<=mid)return query_max(L,R,p<<1);
    else if(L>mid)return query_max(L,R,p<<1|1);
    else{
        P p1=query_max(L,mid,p<<1);
        P p2=query_max(mid+1,R,p<<1|1);
        return p1.index>p2.index?p1:p2;
    }
}
P query_min(int L,int R,int p){
    if(tree[p].L==L&&tree[p].R==R)
        return tree[p].mi;
    int mid=(tree[p].L+tree[p].R)>>1;
    if(R<=mid)return query_min(L,R,p<<1);
    else if(L>mid)return query_min(L,R,p<<1|1);
    else{
        P p1=query_min(L,mid,p<<1);
        P p2=query_min(mid+1,R,p<<1|1);
        return p1.index<p2.index?p1:p2;
    }
}
