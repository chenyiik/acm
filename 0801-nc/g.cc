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

bool cmp(char a, char b) { return a >= b; }
bool cmq(char a, char b) { return a == b; }

long long f(int i, int j, bool c(char, char))
{
	if (j == m) return 1;
	if (i == n) return 0;
	if (dp[i][j] > -1) return dp[i][j];
	if (c(s[i], t[j])) 
		return dp[i][j] = (f(i + 1, j, c) + f(i + 1, j + 1, c)) % mod;
	return dp[i][j] = f(i + 1, j, c);
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
		memset(dp, -1, sizeof(dp));
		ans = (ans + f(0, 0, cmp)) % mod;
		memset(dp, -1, sizeof(dp));
		ans = (ans - f(0, 0, cmq) + mod) % mod;
		printf("%lld\n", ans);
	}
	return 0;
}
