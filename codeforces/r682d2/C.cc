#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int maxn = 105;
int a[maxn][maxn];

void p(int n, int m)
{
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			printf("%d%c", a[i][j], " \n"[j == m]);
}

bool dfs(int i, int j, int n, int m)
{
	if (j > m) j = 1, i++;
	if (i > n)
	{
		p(n, m);
		return true;
	}
	if (j < m && a[i][j] == a[i][j + 1] || i < n && a[i][j] == a[i + 1][j])
	{
		a[i][j]++;
		if (a[i][j] != a[i - 1][j] && a[i][j] != a[i][j - 1] && dfs(i, j + 1, n, m))
			return true;
		a[i][j]--;
		if (a[i][j] != a[i - 1][j] && a[i][j] != a[i][j - 1] && dfs(i, j + 1, n, m))
			return true;
	}
	else
	{
		if (a[i][j] != a[i - 1][j] && a[i][j] != a[i][j - 1] && dfs(i, j + 1, n, m))
			return true;
		a[i][j]++;
		if (a[i][j] != a[i - 1][j] && a[i][j] != a[i][j - 1] && dfs(i, j + 1, n, m))
			return true;
		a[i][j]--;
	}
	return false;
}

int main()
{
	int t; scanf("%d", &t);
	while (t--)
	{
		int n, m; scanf("%d%d", &n, &m);
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= m; j++)
				scanf("%d", &a[i][j]);
		if (!dfs(1, 1, n, m))
			return 1;
	}
	return 0;
}
