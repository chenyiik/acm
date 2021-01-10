#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

void add(unordered_map<int, pair<int, int>> &M, int u, int v)
{
	if (M.find(u) == M.end()) M[u] = make_pair(-1, -1);
	(M[u].first == -1 ? M[u].first : M[u].second) = v;
}

int main()
{
	int _; scanf("%d", &_);
	while (_--)
	{
		unordered_map<int, bool> vis;
		unordered_map<int, pair<int, int>> M;
		int n; scanf("%d", &n);
		while (n--)
		{
			int u, v; scanf("%d%d", &u, &v);
			vis[u] = vis[v] = false;
			add(M, u, v), add(M, v, u);
		}
		int ans = 0;
		for (pair<int, bool> i : vis)
		{
			if (i.second) continue;
			int t = i.first, ret = 0;
			while (true)
			{
				vis[t] = true, ret++;
				if (!vis[M[t].first]) t = M[t].first;
				else if (!vis[M[t].second]) t = M[t].second;
				else break;
			}
			ans = max(ans, ret);
		}
		printf("%d\n", ans);
	}
	return 0;
}
