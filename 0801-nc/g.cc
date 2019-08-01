#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int maxn = 3005, mod = 998244353;
char s[maxn], t[maxn];
long long c[maxn][maxn], dp[maxn][maxn];
int n, m;

void init()
{
	for (int i = 0; i <= 3000; i++)
	{
		c[i][0] = 1;
		for (int j = 1; j <= i; j++)
			c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % mod;
	}
}

long long f(int i, int j)
{
	if (i == n || j == m) return 0;
	if (dp[i][j] > -1) return dp[i][j];
	if (s[i] > t[j])
		return dp[i][j] = (f(i + 1, j) + c[n - i - 1][m - j - 1]) % mod;
	if (s[i] == t[j]) 
		return dp[i][j] = (f(i + 1, j) + f(i + 1, j + 1)) % mod;
	return dp[i][j] = f(i + 1, j);
}

int main()
{
	init();
	int T;
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d%d%s%s", &n, &m, s, t);
		long long ans = 0;
		for (int i = 0; i < n && n - i - 1 >= m; i++)
			if (s[i] > '0')
			{
				for (int j = m; j <= n - i - 1; j++)
					ans = (ans + c[n - i - 1][j]) % mod;
			}
		//memset(dp, -1, sizeof(dp));
		for (int i = 0; i < n + 5; i++)
			for (int j = 0; j < m + 5; j++)
				dp[i][j] = -1;
		ans = (ans + f(0, 0)) % mod;
		printf("%lld\n", ans);
	}
	return 0;
}
