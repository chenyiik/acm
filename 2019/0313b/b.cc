#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct P
{
	int v, d;
	P(int V, int D) : v(V), d(D) {}
};

struct R
{
	int ac, dis;
	R(int A, int D) : ac(A), dis(D) {}
	R(const R &o) : ac(o.ac), dis(o.dis) {}
};

const int maxN = 50005, logN = 18;
vector<P> G[maxN];
int parent[logN][maxN], dist[logN][maxN], depth[maxN];
int n = 0, c = 0;

void dfs(int u, int p, int d)
{
	parent[0][u] = p;
	depth[u] = d;
	for (int i = 0; i < G[u].size(); i++)
		if (G[u][i].v != p)
		{
			dist[0][G[u][i].v] = G[u][i].d;
			dfs(G[u][i].v, u, d + 1);
		}
}

void init()
{
	for (int i = 0; i < n; i++)
		G[i].clear();
	int m = n - 1;
	while (m--)
	{
		int x, y, d;
		scanf("%d%d%d", &x, &y, &d);
		G[x].push_back(P(y, d));
		G[y].push_back(P(x, d));
	}
	memset(parent, -1, sizeof(parent));
	dfs(0, -1, 0);
	for (int k = 0; k + 1 < logN; k++)
		for (int i = 0; i < n; i++)
		{
			if (parent[k][i] == -1)
				parent[k + 1][i] = -1;
			else
			{
				if ((parent[k + 1][i] = parent[k][parent[k][i]]) != -1)
					dist[k + 1][i] = dist[k][i] + dist[k][parent[k][i]];
			}
		}
}

R lca(int u, int v)
{
	int ans = 0;
	if (depth[u] > depth[v])
		swap(u, v);
	for (int k = 0; k < logN; k++)
		if ((depth[v] - depth[u]) >> k & 1)
		{
			ans += dist[k][v];
			v = parent[k][v];
		}
	if (u == v)
		return R(u, ans);
	for (int k = logN - 1; k >= 0; k--)
		if (parent[k][u] != parent[k][v])
		{
			ans += dist[k][u] + dist[k][v];
			u = parent[k][u];
			v = parent[k][v];
		}
	return R(parent[0][u], ans + dist[0][u] + dist[0][v]);
}

int main()
{
	bool caseB = false;
	while (~scanf("%d", &n))
	{
		if (caseB)
			puts("");
		else
			caseB = true;
		init();
		scanf("%d", &c);
		while (c--)
		{
			int u, v, w;
			scanf("%d%d%d", &u, &v, &w);
			R x(lca(u, v)), y(lca(u, w)), z(lca(v, w));
			int ans;
			if (x.ac == y.ac && y.ac == z.ac)
			{
				if (u == x.ac)
					ans = z.dis;
				else if (v == x.ac)
					ans = y.dis;
				else if (w == x.ac)
					ans = x.dis;
				else
					ans = x.dis + lca(x.ac, w).dis;
			}
			else if (x.ac == y.ac)
				ans = z.dis + lca(z.ac, u).dis;
			else if (x.ac == z.ac)
				ans = y.dis + lca(y.ac, v).dis;
			else //if (y.ac == z.ac)
				ans = x.dis + lca(x.ac, w).dis;
			printf("%d\n", ans);
		}
	}
	return 0;
}
