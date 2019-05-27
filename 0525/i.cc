#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int maxv = 1000000 + 5, maxm = maxv, maxlogv = 21;
int root, parent[maxlogv][maxv], depth[maxv];
vector<int> G[maxv];
void dfs(int v, int p, int d);
void init(int V);
int lca(int u, int v);

int val[maxv], n, m, soot, cnt = 0, nu[maxv], pj[maxv];
vector<int> H[maxv], S[maxm];
void read();
void dfs(int u, int fa);

int main()
{
	read();
	dfs(soot, -1);
	root = 0;
	for (int i = 0; i < n; i++)
		pj[nu[i]] = val[i];
	for (int i = 0; i < m; i++)
		S[i].push_back(0);
	for (int i = 0; i < n; i++)
		S[pj[i]].push_back(i);
	init(n);
	for (int i = 0; i < m; i++)
	{
		int ans = S[i].size() > 1 ? 1 : 0, t = n;
		while (S[i].size() > 1)
		{
			int u = S[i][S[i].size() - 1];
			int v = S[i][S[i].size() - 2];
			S[i].pop_back(), S[i].pop_back();
			if (v <= u)
			{
				int w = lca(u, v);
				S[i].push_back(w);
				ans += depth[u] + depth[v] - 2 * depth[w];
			}
			else
			{
				int w = lca(t, v);
				S[i].push_back(u);
				ans += depth[v] - depth[w];
			}
			t = v;
		}
		printf("%d%c", ans, " \n"[i + 1 == m]);
	}
	return 0;
}

void dfs(int u, int fa)
{
	nu[u] = cnt++;
	if (fa != -1)
		G[nu[u]].push_back(nu[fa]);
	for (auto v : H[u])
	{
		dfs(v, u);
		G[nu[u]].push_back(nu[v]);
	}
}

void read()
{
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &val[i]);
		val[i]--;
	}
	for (int i = 0; i < n; i++)
	{
		int x;
		scanf("%d", &x);
		x--;
		if (x == -1)
			soot = i;
		else
			H[x].push_back(i);
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
