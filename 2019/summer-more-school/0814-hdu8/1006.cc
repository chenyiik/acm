#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef long long LL;

const LL oo = 0x7fffffffffffffffLL;
const int maxn = int(2e5) + 5;
LL a[maxn], dp[2][maxn][2];

vector<int> G[maxn];
LL tot = 0;
void dfs(int u, int fa)
{
	if (G[u].size() == 1)
		dp[0][u][0] = dp[0][u][1] = dp[1][u][0] = dp[1][u][1] = a[u];
	else
		for (int v : G[u]) if (v != fa)
		{
			dfs(v, u);
			LL o = dp[1][v][0] + a[u];
			if (o > dp[0][u][0])
				dp[0][u][1] = dp[0][u][0], dp[0][u][0] = o;
			else if (o > dp[0][u][1])
				dp[0][u][1] = o;
			o = dp[0][v][0] + a[u];
			if (o < dp[1][u][0])
				dp[1][u][1] = dp[1][u][0], dp[1][u][0] = o;
			else if (o < dp[1][u][1])
				dp[1][u][1] = o;
		}
}

LL ans; 
void efs(int u, int fa, LL up, LL uq)
{
	if (u > 1)
		ans = G[u].size() == 1 ? max(ans, up) : max(ans, min(dp[1][u][0], up));
	for (int v : G[u]) if (v != fa)
	{
		if (G[u].size() == 2)
			efs(v, u, uq + a[v], up + a[v]);
		else
		{
			LL o = dp[0][u][0] != dp[1][v][0] + a[u] ? dp[0][u][0] : dp[0][u][1];
			LL p = (u > 1 ? max(o, uq) : o) + a[v];
			o = dp[1][u][0] != dp[0][v][0] + a[u] ? dp[1][u][0] : dp[1][u][1];
			LL q = (u > 1 ? min(o, up) : o) + a[v];
			efs(v, u, p, q);
		}
	}
}

int main()
{
	int _; scanf("%d", &_);
	while (_--)
	{
		int n; scanf("%d", &n);
		for (int i = 1; i <= n; i++)
			scanf("%lld", &a[i]);
		for (int i = 1; i <= n; i++)
		{
			LL _; scanf("%lld", &_);
			a[i] -= _;
			dp[0][i][0] = dp[0][i][1] = -oo;
			dp[1][i][0] = dp[1][i][1] = +oo;
			G[i].clear();
		}
		for (int i = 1; i < n; i++)
		{
			int _, __; scanf("%d%d", &_, &__);
			G[_].push_back(__), G[__].push_back(_);
		}
		G[1].push_back(0), dfs(1, 0);
		ans = dp[1][1][0], efs(1, 0, a[1], a[1]);
		printf("%lld\n", ans);
	}
	return 0;
}
