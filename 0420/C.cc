#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int maxn = int(1e5) + 5, maxm = int(1e5) + 5;
struct P { int u, v, w; } t[maxm], s[maxm];
vector<P> G[maxn];
bool b[maxn];
int p[maxn], r[maxn];

int find(int x);

int main()
{
	int T; scanf("%d", &T);
	while (T--)
	{
		int n, m; scanf("%d%d", &n, &m);
		for (int i = 0; i < m; i++)
			scanf("%d%d%d", &t[i].u, &t[i].v, &t[i].w);
		for (int i = 0; i <= n; i++) 
		{
			b[i] = false;
			G[i].clear();
		}
		int k; scanf("%d", &k);
		for (int i = 0; i < k; i++)
		{
			int x; scanf("%d", &x);
			b[x] = true;
		}
		if (n == 2)
		{
			int ans = 0x7fffffff;
			for (int i = 0; i < m; i++)
				ans = min(ans, t[i].w);
			if (ans == 0x7fffffff)
				puts("Impossible");
			else
				printf("%d\n", ans);
			continue;
		}
		int sn = 0;
		for (int i = 0; i < m; i++)
		{
			const P &e = t[i];
			if (!b[e.u]) G[e.v].push_back({e.v, e.u, e.w});
			if (!b[e.v]) G[e.u].push_back({e.u, e.v, e.w});
			if (!b[e.u] && !b[e.v]) s[sn++] = e;
		}
		long long ans = 0;
		bool flag = false;
		for (int i = 1; i <= n; i++) if (b[i])
		{
			if (G[i].size() == 0)
			{
				flag = true;
				break;
			}
			int value = 0x7fffffff;
			for (int j = 0; j < G[i].size(); j++)
				value = min(value, G[i][j].w);
			ans += value;
		}
		if (flag)
		{
			puts("Impossible");
			continue;
		}
		for (int i = 1; i <= n; i++) p[i] = i;
		for (int i = 0; i < sn; i++) r[i] = i;
		sort(r, r + sn, [](int i, int j) { return s[i].w < s[j].w; });
		for (int i = 0; i < sn; i++)
		{
			int e = r[i], x = find(s[e].u), y = find(s[e].v);
			if (x != y)
			{
				ans += s[e].w;
				p[x] = y;
			}
		}
		int x = 1;
		while (x <= n && b[x])
			x++;
		if (x == n + 1)
		{
			puts("Impossible");
			continue;
		}
		for (int y = x + 1; y <= n; y++)
		{
			if (!b[y] && find(x) != find(y))
			{
				flag = true;
				break;
			}
		}
		if (flag)
		{
			puts("Impossible");
			continue;
		}
		printf("%lld\n", ans);
	}
	return 0;
}

int find(int x) { return p[x] == x ? x : p[x] = find(p[x]); }
