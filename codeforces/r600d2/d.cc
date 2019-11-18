#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

const int maxn = int(2e5) + 5;
vector<int> v[maxn];
bool mark[maxn];
int ans = 0;

int bfs(int s)
{
	queue<int> Q;
	int maxd = s;
	Q.push(s);
	mark[s] = true;
	while (!Q.empty())
	{
		int u = Q.front(); Q.pop();
		for (int i : v[u]) if (!mark[i])
		{
			maxd = max(maxd, i);
			Q.push(i);
			mark[i] = true;
		}
	}
	return maxd;
}

int find(int s)
{
	int r = bfs(s);
	for (int i = s; i <= r; i++) if (!mark[i])
		ans++, r = max(r, bfs(i));
	return r;
}

int main()
{
	int n, m; scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		v[x].push_back(y);
		v[y].push_back(x);
	}
	for (int i = 1; i <= n; i++)
	{
		if (mark[i])
			continue;
		i = find(i);
	}
	printf("%d\n", ans);
	return 0;
}
