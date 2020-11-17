#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int maxn = 5005;
char s[maxn], t[maxn];
int f[maxn][maxn];

int main()
{
	int n, m; scanf("%d%d", &n, &m);
	scanf("%s%s", s + 1, t + 1);
	int ans = 0;
	for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++)
	{
		f[i][j] = s[i] == t[j] ? f[i - 1][j - 1] + 2 : 0;
		f[i][j] = max(f[i][j], f[i - 1][j] - 1);
		f[i][j] = max(f[i][j], f[i][j - 1] - 1);
		ans = max(ans, f[i][j]);
	}
	printf("%d\n", ans);
	return 0;
}
