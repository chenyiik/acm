#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

const int maxn = int(1e5) + 10;
vector<int> G[maxn];
vector<int> H[maxn];

struct P { int u, v, d; } e[maxn];
bool cmp(P a, P b)
{
	return a.u > b.u;
}

int p[maxn];
int find(int x) { return p[x] == x ? x : p[x] = find(p[x]); } 
bool vis[maxn];
bool mark[maxn];

bool cmq(int a, int b) { return a > b; }

void dfs(int u)
{
	mark[u] = true;
	sort(H[u].begin(), H[u].end(), cmq);
	for (int i : H[u]) if (!mark[i])
	{
		G[u].push_back(i);
		G[i].push_back(u);
		dfs(i);
	}
}

int main()
{
	int _; scanf("%d", &_);
	while (_--)
	{
		int n, m; scanf("%d%d", &n, &m);
		for (int i = 1; i <= n; i++) H[i].clear(), G[i].clear(), p[i] = i, vis[i] = false, mark[i] = false;
		for (int i = 0; i < m; i++)
		{
			scanf("%d%d", &e[i].u, &e[i].v);
			if (e[i].u < e[i].v) swap(e[i].u, e[i].v);
			H[e[i].u].push_back(e[i].v), H[e[i].v].push_back(e[i].u);
			//e[i].d = e[i].u + e[i].v;
		}
		//sort(e, e + m, cmp);
		/*
		for (int i = 0; i < m; i++)
		{
			cout << '\t' << e[i].u << ' ' << e[i].v << endl;
			int x = find(e[i].u), y = find(e[i].v);
			if (x == y) continue;
			p[x] = y;
			G[e[i].u].push_back(e[i].v), G[e[i].v].push_back(e[i].u);
		}
		*/
		dfs(1);
		int nnn = 0;
		priority_queue<int, vector<int>, greater<int>> Q;
		Q.push(1);
		vis[1] = true;
		while (!Q.empty())
		{
			int u = Q.top(); Q.pop();
			printf("%d%c", u, " \n"[++nnn == n]);
			for (int i : G[u]) if (!vis[i])
				Q.push(i), vis[i] = true;
		}
	}
	return 0;
}
