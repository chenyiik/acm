#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int maxn = int(1e5) + 5, maxm = 35;
int a[maxn][maxm];
int c[maxm];

int main()
{
	for (int n, q; ~scanf("%d%d", &n, &q); )
	{
		memset(c, 0, sizeof(c));
		for (int i = 1; i <= n; i++)
		{
			int x; scanf("%d", &x);
			memset(a[i], 0, sizeof(int) * maxm);
			for (int j = 0; x; j++)
			{
				c[j] += a[i][j] = x & 1;
				x >>= 1;
			}
		}
		while (q--)
		{
			int x; scanf("%d", &x);
			int ans0 = 0, ans1 = 0, ans2 = 0;
			for (int i = maxm - 1; i >= 0; i--)
			{
				ans0 <<= 1, ans1 <<= 1, ans2 <<= 1;
				if (c[i] - a[x][i] == n - 1) ans0++;
				if (c[i] - a[x][i] > 0) ans1++;
				if ((c[i] - a[x][i]) % 2 == 1) ans2++;
			}
			printf("%d %d %d\n", ans0, ans1, ans2);
		}
	}
	return 0;
}
