#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct P { int v, dist; };

const int maxN = static_cast<int>(1e4) + 7;
vector<P> G[maxN];

P down[maxN], down2[maxN];
int ans[maxN];

int dfs(int u)
{
	for (auto i : G[u])
	{
		int d = dfs(i.v) + i.dist;
		if (d > down[u].dist)
		{
			down2[u] = down[u];
			down[u] = {i.v, d};
		}
		else if (d > down2[u].dist)
			down2[u] = {i.v, d};
	}
	return down[u].dist;
}

void dfs(int u, int up)
{
	ans[u] = max(up, down[u].dist);
	for (auto i : G[u])
		dfs(i.v, i.dist + max(up, i.v == down[u].v ? down2[u].dist : down[u].dist));
}

int main()
{
	for (int n = 0; ~scanf("%d", &n); )
	{
		memset(down, 0, sizeof(down));
		memset(down2, 0, sizeof(down2));
		vector<P>().swap(G[1]);
		for (int i = 2; i <= n; i++)
		{
			vector<P>().swap(G[i]);
			int x = 0, y = 0;
			scanf("%d%d", &x, &y);
			G[x].push_back({i, y});
		}
		dfs(1);
		dfs(1, 0); 
		for (int i = 1; i <= n; i++)
			printf("%d\n", ans[i]);
	}
	return 0;
}
