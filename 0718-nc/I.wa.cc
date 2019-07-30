#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef long long LL;

const int maxn = 100000 + 10, maxl = 1 << 17;
LL maxv[maxl * 4 + 5], maxw[maxl * 4 + 5];

int ql, qr; 

LL query(LL a[], int o = 1, int L = 1, int R = maxl) //get max in [ql, qr]
{
	int M = L + (R - L) / 2; LL ans = 0;
	if (ql <= L && R <= qr)
		return a[o];
	if (ql <= M)
		ans = max(ans, query(a, o * 2, L, M));
	if (M < qr)
		ans = max(ans, query(a, o * 2 + 1, M + 1, R));
	return ans;
}

int p; LL vv; 

void update(LL a[], int o = 1, int L = 1, int R = maxl) //let A[p] = v;
{
	int M = L + (R - L) / 2;
	if (L == R)
		a[o] = vv;
	else
	{
		if (p <= M)
			update(a, o * 2, L, M);
		else
			update(a, o * 2 + 1, M + 1, R);
		a[o] = max(a[o * 2], a[o * 2 + 1]);
	}
}

struct P { int x, y; LL a, b, v; } c[maxn];
vector<P> v[maxn];

int main()
{
	for (int n; ~scanf("%d", &n); )
	{
		for (int i = 0; i < n; i++)
			scanf("%d%d%lld%lld", &c[i].x, &c[i].y, &c[i].a, &c[i].b);
		sort(c, c + n, [](const P &a, const P &b) { return a.x < b.x; });
		int mx = 1, my = 2; c[n].x = c[n].y = -1;
		for (int i = 0; i < n; i++)
			c[i].x = c[i].x == c[i + 1].x ? mx : mx++;
		for (int i = 1; i < mx; i++)
			v[i].clear(), v[i].push_back(P{i, 1, 0, 0, 0});
		sort(c, c + n, [](const P &a, const P &b) { return a.y < b.y; });
		for (int i = 0; i < n; i++)
		{
			c[i].y = c[i].y == c[i + 1].y ? my : my++;
			v[c[i].x].push_back(c[i]), v[c[i].x][0].v += c[i].a;
		}
		LL *mv = maxv, *mw = maxw, ans = 0;
		for (int i = 1; i < mx; i++)
		{
			for (int j = 1; j < v[i].size(); j++)
				v[i][j].v = v[i][j - 1].v + v[i][j].b - v[i][j].a;
			int s = v[i].size();
			for (int j = 0; j < s; j++)
			{
				ql = 1, qr = j + 1 == v[i].size() ? my : v[i][j + 1].y - 1;
				LL t;
				ans = max(ans, v[i][j].v += t = query(mv));
				for (int j = 0; j < v[i - 1].size(); j++)
					if (v[i - 1][j].v == t)
					{
						t = j;
						break;
					}
				p = v[i][j].y = max(v[i][j].y, (int)t);
				vv = v[i][j].v, update(mw);
			}
			for (int j = 0; j < v[i - 1].size(); j++)
				p = v[i - 1][j].y, vv = -v[i - 1][j].v, update(mv);
			swap(mv, mw);
		}
		for (int j = 0; j < v[mx - 1].size(); j++)
			p = v[mx - 1][j].y, vv = -v[mx - 1][j].v, update(mv);
		printf("%lld\n", ans);
	}
	return 0;
}
