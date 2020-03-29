#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

const int maxn = 100000 + 100;
vector<int> H[maxn];
struct P { int u, v; bool vis; } e[maxn];

void make_tree();
void init(int V);
int lca(int u, int v);

int tot[maxn];

int main()
{
	int n, m; scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++)
	{
		scanf("%d%d", &e[i].u, &e[i].v);
		H[e[i].u].push_back(i);
		H[e[i].v].push_back(i);
	}
	make_tree();
	init(n);
	int ans = 0;
	for (int i = 0; i < m; i++) if (!e[i].vis)
	{
		int nd = lca(e[i].u, e[i].v);
		ans += (1 << tot[nd]++);
	}
	printf("%d\n", ans);
	return 0;
}

const int maxv = 1000000 + 10, maxlogv = 27;
vector<int> G[maxv];
int root = 1;
int parent[maxlogv][maxv];
int depth[maxv];

void make_tree()
{
	static int vis[maxn];
	vis[1] = true;
	queue<int> Q;
	Q.push(1);
	while (!Q.empty())
	{
		int u = Q.front(); Q.pop();
		for (int i : H[u]) if (!e[i].vis)
		{
			int v = e[i].u != u ? e[i].u : e[i].v;
			if (vis[v])
				continue;
			G[u].push_back(v);
			G[v].push_back(u);
			vis[v] = e[i].vis = true;
			Q.push(v);
		}
	}
}

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
		for (int v = 1; v <= V; v++)
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
