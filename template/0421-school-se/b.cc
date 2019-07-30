#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 307;
double a[N], f[N][N][2];
int n = 0;

double dfs(int x, int y, int k)
{
	if (x == n || y == n)
		return 0;
	if (f[x][y][k] > -0.5)
		return f[x][y][k];
	if (k == 0)
		f[x][y][k] = (a[x] * (dfs(x + 1, y, 0) + 1) + (1 - a[x]) + (1 - a[x]) * a[y] * (dfs(x, y + 1, 1) + 1) + (1 - a[x] - a[y] + a[x] * a[y])) / (a[x] + a[y] - a[x] * a[y]);
	else
		f[x][y][k] = (a[y] * (dfs(x, y + 1, 1) + 1) + (1 - a[y]) + (1 - a[y]) * a[x] * (dfs(x + 1, y, 0) + 1) + (1 - a[x] - a[y] + a[x] * a[y])) / (a[x] + a[y] - a[x] * a[y]);
	return f[x][y][k];
}

int main()
{
	int t = 0;
	scanf("%d", &t);
	while (t--)
	{
		scanf("%d", &n);
		for (int i = 0; i < n; i++)
			scanf("%lf", &a[i]);
		for (int i = 0; i <= n; i++) for (int j = 0; j <= n; j++)
			f[i][j][0] = f[i][j][1] = -1.0;
		printf("%.4f\n", dfs(0, 0, 0));
	}
	return 0;
}
