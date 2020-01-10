#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int n, m;
	cin >> n >> m;
	const int maxn = 3005;
	static int sum[maxn][maxn], lx[maxn][maxn];
	for (int i = 1; i <= n; i++)
	{
		static char s[maxn];
		scanf("%s", s + 1);
		for (int j = 1; j <= m + 1; j++)
		{
			sum[i][j] = sum[i][j - 1] + (s[j] == '1');
			lx[i][j] = s[j] == '1' ? lx[i - 1][j] + 1 : 0;
		}
	}
	int st[maxn], size = 0, pre[maxn], ans = 0;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m + 1; j++)
		{
			int pos = j;
			while (lx[i][j] < st[size])
			{
				if (sum[i + 1][j - 1] - sum[i + 1][pre[size] - 1] < j - pre[size])
					ans++;
				pos = pre[size--];
			}
			if (lx[i][j] > st[size])
			{
				st[++size] = lx[i][j];
				pre[size] = pos;
			}
		}
	cout << ans << endl;
	return 0;
}
