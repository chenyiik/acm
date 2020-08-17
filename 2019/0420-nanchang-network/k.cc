#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int maxN = static_cast<int>(1e5) + 9;
int a[maxN];
int f[4][4][maxN];

int main()
{
	int t = 0;
	scanf("%d", &t);
	while (t--)
	{
		int n = 0;
		scanf("%d", &n);
		for (int i = 1; i <= n; i++)
			scanf("%d", &a[i]);
		for (int k = 0; k < 4; k++)
			for (int i = 1; i <= n; i++)
			{
				if ((i + 4 - k) % 4 == 1)
				{
					f[k][1][i] = f[k][1][i - 1] ^ a[i];
					f[k][2][i] = f[k][2][i - 1] ^ a[i];
					f[k][3][i] = f[k][3][i - 1];
					f[k][0][i] = f[k][0][i - 1];
				}
				else if ((i + 4 - k) % 4 == 2)
				{
					f[k][1][i] = f[k][1][i - 1];
					f[k][2][i] = f[k][2][i - 1] ^ a[i];
					f[k][3][i] = f[k][3][i - 1] ^ a[i];
					f[k][0][i] = f[k][0][i - 1];
				}
				if ((i + 4 - k) % 4 == 3)
				{
					for (int j = 0; j < 4; j++)
						f[k][j][i] = f[k][j][i - 1];
				}
				if ((i + 4 - k) % 4 == 0)
				{
					for (int j = 0; j < 4; j++)
						f[k][j][i] = f[k][j][i - 1];
				}
			}
		int q = 0;
		scanf("%d", &q);
		while (q--)
		{
			int l, r;
			scanf("%d%d", &l, &r);
			int j = (r - l + 1) % 4;
			int k = (l-1) % 4;
			printf("%d\n", f[k][j][r] ^ f[k][j][l - 1]);
		}
	}
	return 0;
}
