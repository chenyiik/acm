#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

const int maxN = 5007, oo = 0x7fffffff;
int v[maxN * 2], min_value = +oo;
vector<int> G[maxN];
bool vis[maxN], locking = true;
enum{white, red, black} color[maxN];

bool find_loop(int father = 0, int u = 1)
{
	if (color[u] == red)
	{
		color[u] = black;
		return true;
	}
	color[u] = red;
	for (int i = 0; i < G[u].size(); i++)
	{
		int son = v[G[u][i]];
		if (son == father)
			continue;
		bool b = find_loop(u, son);
		if (color[u] == black)
			return false;
		if (b)
		{
			color[u] = black;
			return true;
		}
	}
	return false;
}

void dfs(int father = 0, int u = 1)
{
	if (vis[u])
		return;
	vis[u] = true;
	printf("%d ", u);
	if (!locking || color[u] != black)
	{
		for (int i = 0; i < G[u].size(); i++)
		{
			int son = v[G[u][i]];
			if (son == father)
				continue;
			dfs(u, son);
		}
	}
	else
	{
		for (int i = 0; i < G[u].size(); i++)
		{
			int son = v[G[u][i]];
			if (son == father)
				continue;
			if (!locking || color[son] != black)
				dfs(u, son);
			else
			{
				//cout << '"';
				for (int j = i + 1; j < G[u].size(); j++)
				{
					//cout << v[G[u][j]] << ' ';
					if (v[G[u][j]] == father)
						continue;
					min_value = v[G[u][j]];
					//cout << min_value << '"' << ' ';
					break;
				}
				//cout << "'" << son << ' ' << min_value << "' ";
				if (son < min_value)
					dfs(u, son);
				else
					locking = false;
			}
		}
	}
}

bool cmp(int a, int b) { return v[a] < v[b]; }

int main()
{
	int n = 0, m = 0;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++)
	{
		int x = 0, y = 0;
		scanf("%d%d", &x, &y);
		G[x].push_back(i * 2);
		G[y].push_back(i * 2 + 1);
		v[i * 2] = y;
		v[i * 2 + 1] = x;
	}
	for (int i = 1; i <= n; i++)
		sort(G[i].begin(), G[i].end(), cmp);
	if (m == n)
		find_loop();
	dfs();
	puts("");
	return 0;
}
