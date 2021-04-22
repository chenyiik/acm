#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int maxn = int(1e5) + 5, maxm = int(1e5) + 5;
struct P { int u, v, w; } t[maxm];
vector<P> G[maxn];
bool b[maxn];
int p[maxn];

int find(int x) { return p[x] == x ? x : p[x] = find(p[x]); }

int main()
{
	int T; scanf("%d", &T);
	while (T--)
	{
		int n, m; scanf("%d%d", &n, &m);
		for (int i = 1; i <= n; i++) b[i] = false, G[i].clear(), p[i] = i;
		for (int i = 0; i < m; i++) scanf("%d%d%d", &t[i].u, &t[i].v, &t[i].w);
		int k, kkk; scanf("%d", &k);
		while (k--) scanf("%d", &kkk), b[kkk] = true;
		if (n == 2)
		{
			int ans = 0x7fffffff;
			for (int i = 0; i < m; i++) if (t[i].u != t[i].v)
				ans = min(ans, t[i].w);
			printf("%d\n", ans);
			continue;
		}
		vector<int> r;
		for (int i = 0; i < m; i++)
		{
			const P &e = t[i];
			G[e.u].push_back(e);
			G[e.v].push_back({e.v, e.u, e.w});
			if (!b[e.u] && !b[e.v]) r.push_back(i);
		}
		long long ans = 0;
		bool flag = false;
		for (int i = 1; i <= n; i++) if (b[i])
		{
			int value = 0x7fffffff;
			for (P j : G[i]) if (!b[j.v])
				value = min(value, j.w);
			if (value == 0x7fffffff) { flag = true; break; }
			ans += value;
		}
		if (flag) { puts("Impossible"); continue; }
		sort(r.begin(), r.end(), [](int i, int j) { return t[i].w < t[j].w; });
		for (int i : r)
		{
			const P &e = t[i];
			int x = find(e.u), y = find(e.v);
			if (x != y) ans += e.w, p[x] = y;
		}
		int x = 1;
		while (x <= n && b[x]) x++;
		if (x == n + 1) { puts("Impossible"); continue; }
		for (int y = x + 1; y <= n; y++)
			if (!b[y] && find(x) != find(y)) { flag = true; break; }
		if (flag) { puts("Impossible"); continue; }
		printf("%lld\n", ans);
	}
	return 0;
}
