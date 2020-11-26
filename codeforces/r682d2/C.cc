#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int maxn = 105;
int a[maxn][maxn];

int main()
{
	int t; scanf("%d", &t);
	while (t--)
	{
		int n, m; scanf("%d%d", &n, &m);
		for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++)
		{
			int x; scanf("%d", &x);
			if ((i + j) % 2 != x % 2)
				x++;
			printf("%d%c", x, " \n"[j == m]);
		}
	}
	return 0;
}
