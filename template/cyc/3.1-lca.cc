#include "cyc.h"

const int maxv = 1000000 + 10;
const int maxlogv = 27;

vector<int> G[maxv];
int root;

int parent[maxlogv][maxv];
int depth[maxv];

void dfs(int v, int p, int d)
{
	parent[0][v] = p;
	depth[v] = d;
	for (int i = 0; i < G[v].size(); i++)
		if (G[v][i] != p)
			dfs(G[v][i], v, d + 1);
}

void init(int V)
{
	dfs(root, -1, 0);
	for (int k = 0; k + 1 < maxlogv; k++)
		for (int v = 0; v < V; v++)
			if (parent[k][v] < 0)
				parent[k + 1][v] = -1;
			else
				parent[k + 1][v] = parent[k][parent[k][v]];
}

int lca(int u, int v)
{
	if (depth[u] > depth[v])
		swap(u, v);
	for (int k = 0; k < maxlogv; k++)
		if ((depth[v] - depth[u]) >> k & 1)
			v = parent[k][v];
	if (u == v)
		return u;
	for (int k = maxlogv - 1; k >= 0; k--)
		if (parent[k][u] != parent[k][v])
		{
			u = parent[k][u];
			v = parent[k][v];
		}
	return parent[0][u];
}
