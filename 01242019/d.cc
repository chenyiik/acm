#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

char c[505][505];

int main()
{
	int n = 0, m = 0;
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
		scanf("%s", c[i] + 1);
	int ans = 0;
	if (n == 1 || n == 2)
	{
		if (m == 1 || m == 2)
			ans = 0;
		else
		{
			ans = m - 2;
			for (int i = 2; i <= m - 1; i++)
			{
				if (c[1][i] == '#' || c[2][i] == '#')
					ans--;
			}
		}
	}
	else if (m == 1 || m == 2)
	{
		ans = n - 2;
		for (int i = 2; i <= n - 1; i++)
		{
			if (c[i][1] == '#' || c[i][2] == '#')
				ans--;
		}
	}
	else
	{
		for (int i = 2; i <= n - 1; i++)
		{
			for (int j = 2; j <= m - 1; j++)
			{
				if (c[i][j] == '.')
					ans++;
			}
		}
		bool b = false;
		for (int i = 2; i <= n - 1; i++)
			b |= c[i][1] == '#' || c[i][n] == '#';
		for (int i = 2; i <= m - 1; i++)
			b |= c[1][i] == '#' || c[n][i] == '#';
		if (!b)
			ans++;
	}
	printf("%d\n", ans);
	return 0;
}
