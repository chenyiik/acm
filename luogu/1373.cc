#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

typedef long long LL;

const int maxN = 805;
const LL mod = 1000000007;
LL dp[2][maxN][2][20];

int main()
{
	int n = 0, m = 0, k = 0;
	scanf("%d%d%d", &n, &m, &k);
	LL ans = 0;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
		{
			LL x = 0;
			scanf("%lld", &x);
			for (int p = 0; p <= k; p++)
			{
				int q = p + x, r = p - x;
				if (q > k)
					q -= k + 1;
				if (r < 0)
					r += k + 1;
				dp[i & 1][j][0][q] = dp[(i - 1) & 1][j][1][p] + dp[i & 1][j - 1][1][p];
				dp[i & 1][j][0][q] %= mod;
				dp[i & 1][j][1][r] = dp[(i - 1) & 1][j][0][p] + dp[i & 1][j - 1][0][p];
				dp[i & 1][j][1][r] %= mod;
			}
			dp[i & 1][j][0][x]++;
			dp[i & 1][j][0][x] %= mod;
			ans = (ans + dp[i & 1][j][1][0]) % mod;
		}
	printf("%lld\n", ans);
	return 0;
}
