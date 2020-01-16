#include <cstdio>
#include <iostream>
#include <algorithm>
#include <utility>
#include <queue>

using namespace std;

const int maxn = int(1e5) + 5;
struct P { int x, id, v, p; } a[maxn];
int an = 0;

const int M = maxn * 4;
pair<int, int> maxv[M];
int ql, qr; pair<int, int> query(int o, int L, int R); //get max in [ql, qr]
int p; pair<int, int> v; void update(int o, int L, int R); //let A[p] = v;

int main()
{
	int n, k; scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; i++)
	{
		int m, x; scanf("%d", &m);
		while (m--) scanf("%d", &x), a[++an] = {x, i, 0, 0};
	}
	if (an == 0) return puts("0"), 0;
	sort(a + 1, a + 1  + an, [](P a, P b) { return a.x > b.x; });
	int pos = 0;
	queue<pair<int, pair<int, int>>> Q;
	for (int i = 1; i <= an; i++)
	{
		if (a[i].x < a[i - 1].x)
			while (!Q.empty()) p = Q.front().first, v = Q.front().second, update(1, 1, n), Q.pop();
		int l = a[i].id == n ? 1 : a[i].id + 1, r = l + k;
		pair<int, int> ans;
		if (r <= n) ql = l, qr = r, ans = query(1, 1, n);
		else
		{
			ql = l, qr = n, ans = query(1, 1, n);
			ql = 1, qr = r - n, ans = max(ans, query(1, 1, n));
		}
		Q.push(make_pair(a[i].id, make_pair(a[i].v = ans.first + 1, i)));
		a[i].p = ans.second;
		if (a[i].v >= a[pos].v) pos = i;
	}
	printf("%d\n", a[pos].v);
	while (pos) printf("%d %d\n", a[pos].id, a[pos].x), pos = a[pos].p;
	//for (int i = 1; i <= an; i++) cout << a[i].x << '\t' << a[i].id << '\t' << a[i].v<< '\t' << a[i].p << endl;
	return 0;
}


pair<int, int> query(int o, int L, int R)
{
	if (ql <= L && R <= qr) return maxv[o];
	int M = L + (R - L) / 2;
	pair<int, int> ans = make_pair(0, 0);
	if (ql <= M) ans = max(ans, query(o * 2, L, M));
	if (M < qr) ans = max(ans, query(o * 2 + 1, M + 1, R));
	return ans;
}

void update(int o, int L, int R)
{
	int M = L + (R - L) / 2;
	if (L == R) maxv[o] = v;
	else
	{
		if (p <= M) update(o * 2, L, M);
		else update(o * 2 + 1, M + 1, R);
		maxv[o] = max(maxv[o * 2], maxv[o * 2 + 1]);
	}
}
