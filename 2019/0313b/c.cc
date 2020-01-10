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

const int maxN = 10005, logN = 15;
vector<P> G[maxN];
int parent[logN][maxN], dist[logN][maxN], depth[maxN];
int n = 0, m = 0, c = 0;

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
	for (int i = 1; i <= n; i++)
		G[i].clear();
	while (m--)
	{
		int x, y, d;
		scanf("%d%d%d", &x, &y, &d);
		G[x].push_back(P(y, d));
		G[y].push_back(P(x, d));
	}
	memset(parent, 0, sizeof(parent));
	for (int i = 1; i <= n; i++)
		if (parent[0][i] == 0)
			dfs(i, -1, 0);
	for (int k = 0; k + 1 < logN; k++)
		for (int i = 1; i <= n; i++)
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

int lca(int u, int v)
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
		return ans;
	for (int k = logN - 1; k >= 0; k--)
		if (parent[k][u] != parent[k][v])
		{
			ans += dist[k][u] + dist[k][v];
			u = parent[k][u];
			v = parent[k][v];
		}
	if (parent[0][u] == -1)
		return -1;
	return parent[0][u] == -1 ? -1 : ans += dist[0][u] + dist[0][v];
}

void show()
{
	for (int i = 1; i <= n; i++)
		cout << dist[0][i] << ' ';
	cout << endl;
}

int main()
{
	while (~scanf("%d%d%d", &n, &m, &c))
	{
		init();
		//show();
		while (c--)
		{
			int u, v;
			scanf("%d%d", &u, &v);
			int ans = lca(u, v);
			if (ans == -1)
				puts("Not connected");
			else
				printf("%d\n", ans);
		}
	}
	return 0;
}
