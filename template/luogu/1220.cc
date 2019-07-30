#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

int dp[64][2], pre[64][2];

int pos[64], powersum[64];

int main()
{
	int n = 0, c = 0;
	scanf("%d%d", &n, &c);
	c--;
	for (int i = 0; i < n; i++)
	{
		int x = 0;
		scanf("%d%d", &pos[i], &x);
		powersum[i] = i == 0 ? x : powersum[i - 1] + x;
	}
	//for (int i = 0; i < n; i++)
		//cout << powersum[i] << ' ';
	//cout << endl;
	memset(dp, 0x3f, sizeof(dp));
	dp[c][0] = dp[c][1] = 0;
	for (int i = 0; i < n - 1; i++)
	{
		memcpy(pre, dp, sizeof(pre));
		memset(dp, 0x3f, sizeof(dp));
		for (int j = 0; j < n; j++)
		{
			int powerfee = powersum[n - 1] - powersum[min(n - 1, j + i)];// + powersum[j - 1];
			if (j > 0)
				powerfee += powersum[j - 1];
			//cout << j << ' ' << i << ' ' << powersum[n - 1] << ' ' << powersum[min(n - 1, j + i)] << ' ' << powersum[j - 1] << ' ' << powerfee << endl;
			if (pre[j][0] < 0x3f3f3f3f)
			{
				if (j - 1 >= 0)
					dp[j - 1][0] = min(dp[j - 1][0], pre[j][0] + (pos[j] - pos[j - 1]) * powerfee);
				if (j + i + 1 <= n - 1)
					dp[j][1] = min(dp[j][1], pre[j][0] + (pos[j + i + 1] - pos[j]) * powerfee);
			}
			if (pre[j][1] < 0x3f3f3f3f)
			{
				if (j - 1 >= 0)
					dp[j - 1][0] = min(dp[j - 1][0], pre[j][1] + (pos[j + i] - pos[j - 1]) * powerfee);
				if (j + i + 1 <= n - 1)
					dp[j][1] = min(dp[j][1], pre[j][1] + (pos[j + i + 1] - pos[j + i]) * powerfee);
			}
		}
		//for (int j = 0; j < n; j++)
			//printf("%12d%12d\n", dp[j][0], dp[j][1]);
		//cout << endl;
	}
	int ans = 0x7fffffff;
	ans = min(ans, min(dp[0][0], dp[0][1]));
	printf("%d\n", ans);
	return 0;
}
