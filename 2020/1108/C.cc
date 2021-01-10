#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int maxm = 5005, maxn = 1005, mod = int(1e9) + 7;
char s[maxm], t[maxn];
int f[maxn][maxm];

int main()
{
	while (~scanf("%s%s", s + 1, t + 1))
	{
		int m = strlen(s + 1), n = strlen(t + 1);
		memset(f, 0, sizeof(f));
		f[0][0] = 1;
		for (int i = 1; i <= n; i++)
		{
			int c = f[i - 1][0];
			for (int j = 1; j <= m; j++)
			{
				if (t[i] == s[j])
					f[i][j] = c;
				c = (c + f[i - 1][j]) % mod;
			}
		}
		int ans = 0;
		for (int i = 1; i <= m; i++)
			ans = (ans + f[n][i]) % mod;
		printf("%d\n", ans);
	}
	return 0;
}
