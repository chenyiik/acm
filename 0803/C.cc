#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int maxn = int(1e5) + 5;
int a[maxn];
vector<int> G[maxn];
int b[maxn], c[maxn], d[maxn];
const int oo = 0x7fffffff;

void dfs(int u, int fa, int depth)
{
	for (int i : G[u]) if (i != fa)
	{
		dfs(i, u, depth + 1);
	}
}

int main()
{
	int _; scanf("%d", &_);
	while (_--)
	{
		int n; scanf("%d", &n);
		for (int i = 1; i <= n; i++)
		{
			scanf("%d", &a[i]);
			b[i] = c[i] = +oo;
		}
		for (int i = 1; i < n; i++)
		{
			int x, y; scanf("%d%d", &x, &y);
			G[x].push_back(y), G[y].push_back(x);
		}
		dfs(1, 0, 1);
		for (int i = 1; i <= n; i++)
			printf("%d%c", d[i], " \n"[i == n]);
	}
	return 0;
}
