#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>

using namespace std;

vector<pair<int, int>> ans[11];
bool vis[11];

void dfs(int l, int r, int d)
{
	ans[d].push_back(make_pair(l, r - 1));
	if (l + 1 == r)
		return;
	else
	{
		vis[d] = true;
		if (d < 10)
		{
			int mid = (l + r) / 2;
			dfs(l, mid, d + 1);
			dfs(mid, r, d + 1);
		}
	}
}

int main()
{
	int n;
	scanf("%d", &n);
	dfs(1, n + 1, 1);
	int op = 0;
	for (bool i : vis) if (i)
		op++;
	printf("%d\n", op);
	for (int i = 10; i > 0; i--)
	{
		if (!vis[i])
			continue;
		printf("%lu\n", ans[i].size());
		for (const auto &j : ans[i])
			printf("%d %d\n", j.first, j.second);
	}
	return 0;
}
