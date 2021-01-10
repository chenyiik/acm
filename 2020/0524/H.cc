#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

const int maxn = int(1e5) + 10;
struct P { int v, w; bool vis; };
vector<P> G[maxn];
int step[maxn];

int main()
{
	freopen("path.in", "r", stdin);
	int _; scanf("%d", &_);
	while (_--)
	{
		int n, m, u, l, k;
		scanf("%d%d%d%d%d", &n, &m, &u, &l, &k);
		for (int i = 1; i <= n; i++) G[i].clear(), step[i] = -1;
		while (m--)
		{
			int x, y, e; scanf("%d%d%d", &x, &y, &e);
			G[x].push_back({y, e, false}), G[y].push_back({x, e, false});
		}
		int ans = 0;
		queue<int> Q;
		Q.push(u);
		step[u] = 0;
		while (!Q.empty() && step[Q.front()] < k)
		{
			int nd = Q.front(); Q.pop();
			//cout << nd << ' ' << step[nd] << endl;
			for (P &i : G[nd]) if (!i.vis)
			{
				ans = max(ans, i.w), i.vis = true;
				if (step[i.v] == -1)
					Q.push(i.v), step[i.v] = step[nd] + 1;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
