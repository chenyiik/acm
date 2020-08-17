#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

int a[255][255];
int d1[255][255][10], d2[255][255][10];


void init(int n, int b)
{
	for (int k = 0; k < n; k++)
	{
		for (int i = 0; i < n; i++)
		{
			d1[k][i][0] = a[k][i];
			d2[k][i][0] = a[k][i];
		}
		for (int j = 1; (1 << j) <= n; j++)
			for (int i = 0; i + (1 << j) - 1 < n; i++)
			{
				d1[k][i][j] = min(d1[k][i][j - 1], d1[k][i + (1 << (j - 1))][j - 1]);
				d2[k][i][j] = max(d2[k][i][j - 1], d2[k][i + (1 << (j - 1))][j - 1]);
			}
	}
}

int rmq(int p, int l, int r, int q)
{
	int k = 0;
	while ((1 << (k + 1)) <= r - l + 1)
		k++;
	return q == 1 ? min(d1[p][l][k], d1[p][r - (1<<k) + 1][k]) : max(d2[p][l][k], d2[p][r - (1<<k) + 1][k]);
}

int main()
{
	int n = 0, b = 0, k = 0;
	scanf("%d%d%d", &n, &b, &k);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			scanf("%d", &a[i][j]);
	init(n, b);
	while (k--)
	{
		int x = 0, y = 0;
		scanf("%d%d", &x, &y);
		x--, y--;
		int da = 0, xiao = 0x7fffffff;
		for (int i = x; i < x + b; i++)
		{
			da = max(da, rmq(i, y, y + b - 1, 0));
			xiao = min(xiao, rmq(i, y, y + b - 1, 1));
		}
		printf("%d\n", da - xiao);
	}
	return 0;
}
