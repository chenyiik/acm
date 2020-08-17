#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
//segment add

const int maxn = 400000 + 10;

int maxv[maxn], addv[maxn], pm[maxn];

void maintain(int o, int L, int R)
{
	int lc = o * 2, rc = o * 2 + 1;
	maxv[o] = 0, pm[o] = L;
	if (R > L)
	{
		maxv[o] = max(maxv[lc], maxv[rc]);
		if (maxv[lc] >= maxv[rc])
			maxv[o] = maxv[lc], pm[o] = pm[lc];
		else
			maxv[o] = maxv[rc], pm[o] = pm[rc];
	}
	maxv[o] += addv[o];
}

int ql, qr, v;

void update(int o, int L, int R) //let [ql, qr] add v;
{
	if (ql > qr)
		return;
	int lc = o * 2, rc = o * 2 + 1;
	if (ql <= L && qr >= R)
		addv[o] += v;
	else
	{
		int M = L + (R - L) / 2;
		if (ql <= M)
			update(lc, L, M);
		if (qr > M)
			update(rc, M + 1, R);
	}
	maintain(o, L, R);
}

int _max, pos, C;

void query(int o, int L, int R, int add = 0) //get min, max, sum in [ql, qr]
{
	if (ql > qr)
		return;
	if (ql <= L && qr >= R)
	{
		_max = max(_max, maxv[o] + add);
		if (_max == C)
			pos = !pos ? pm[o] : min(pos, pm[o]);
	}
	else
	{
		int M = L + (R - L) / 2;
		if (ql <= M)
		{
			query(o * 2, L, M, add + addv[o]);
		}
		if (qr > M)
		{
			query(o * 2 + 1, M + 1, R, add + addv[o]);
		}
	}
}

vector<int> vp[maxn / 4];

int main()
{
	for (int n, c, k; ~scanf("%d%d%d", &n, &c, &k); )
	{
		C = c;
		for (int i = 0; i < n * 4 + 5; i++) 
			maxv[i] = addv[i] = 0, pm[i] = 1;
		for (int i = 1; i <= c; i++) 
			vp[i].clear(), vp[i].push_back(0);
		int ans = 0;
		for (int i = 1; i <= n; i++)
		{
			int x; scanf("%d", &x);
			ql = qr = i, v = c - 1, update(1, 1, n + 1);
			ql = vp[x].back() + 1, qr = i - 1, v = -1, update(1, 1, n + 1);
			vp[x].push_back(i);
			int p = vp[x].size() - k - 1;
			if (p >= 0)
				ql = vp[x][p] + 1, qr = vp[x][p + 1], v = 1, 
				   update(1, 1, n + 1);
			ql = 1, qr = i, pos = 0, _max = 0, query(1, 1, n + 1);
			if (pos)
				ans = max(ans, i - pos + 1);
		}
		printf("%d\n", ans);
	}
	return 0;
}
