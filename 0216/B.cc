#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int maxn = int(1e5) + 5;
vector<int> v[maxn], G[maxn];
int ret[maxn], cnt[maxn], deep[maxn], tot;
bool vis[maxn];

void init(int n);
int find_loop(int u, int fa, int dep);
void update_graph(int u, int fa, int real_fa);
int find_deepnode(int u, int fa, int dep);
int find_maxdepth(int u, int fa, int dep);

int main()
{
	int t; scanf("%d", &t);
	while (t--)
	{
		int n, m; scanf("%d%d", &n, &m);
		init(n);
		while (m--)
		{
			int x, y; scanf("%d%d", &x, &y);
			if (x == y) continue;
			v[x].push_back(y), v[y].push_back(x);
		}
		for (int i = 1; i <= n; i++) vis[i] = false;
		for (int i = 1; i <= n; i++) if (!vis[i])
			find_loop(i, 0, 1);
		for (int i = 1; i <= n; i++) vis[i] = false;
		for (int i = 1; i <= n; i++) if (!vis[i])
			update_graph(i, 0, 0);
		int maxdepth = 0;
		for (int i = 1; i <= n; i++) vis[i] = false;
		for (int i = 1; i <= n; i++) if (!vis[i])
		{
			int node = find_deepnode(i, 0, 0);
			int depth = find_maxdepth(node, 0, 0);
			maxdepth = max(maxdepth, depth);
		}
		printf("%d\n", tot - maxdepth);
	}
	return 0;
}

int find_maxdepth(int u, int fa, int dep)
{
	vis[u] = true;
	int depth = deep[u] = dep;
	for (int i : G[u]) if (!vis[i])
	{
		int tmp = find_maxdepth(i, u, dep + 1);
		depth = max(depth, tmp);
	}
	return depth;
}

int find_deepnode(int u, int fa, int dep)
{
	vis[u] = true;
	deep[u] = dep;
	int node = u;
	for (int i : G[u]) if (!vis[i])
	{
		int tmp = find_deepnode(i, u, dep + 1);
		if (deep[tmp] > deep[node])
			node = tmp;
	}
	vis[u] = false;
	return node;
}

void update_graph(int u, int fa, int real_fa)
{
	vis[u] = true;
	if (ret[u] == 0 && real_fa != 0)
		G[u].push_back(real_fa), G[real_fa].push_back(u), tot++;
	for (int i : v[u]) if (!vis[i])
		update_graph(i, u, ret[u] == 0 ? u : real_fa);
}

int find_loop(int u, int fa, int dep)
{
	//cout << u << endl;
	deep[u] = dep;
	vis[u] = true;
	bool find_fa = false;
	for (int i : v[u])
	{
		if (i == fa && !find_fa)
		{
			find_fa = true;
			continue;
		}
		if (deep[i] > dep) continue;
		if (vis[i])
			ret[u]++, cnt[i]++;
		else
			ret[u] += find_loop(i, u, dep + 1);
	}
	ret[u] -= cnt[u];
	return ret[u];
}

void init(int n)
{
	for (int i = 1; i <= n; i++)
		v[i].clear(), G[i].clear(), ret[i] = cnt[i] = deep[i] = 0;
	tot = 0;
}

		/*
		for (int i = 1; i <= n; i++)
			cout << i << ' ' << ret[i] << ' ' << cnt[i] << endl;
		for (int i = 1; i <= n; i++)
		{
			cout << i << '\t';
			for (int j : G[i])
				cout << j << ' ';
			cout << endl;
		}
		*/
