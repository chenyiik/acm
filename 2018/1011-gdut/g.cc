#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

int c[15][15];

void init(int n)
{
	memset(c, 0, sizeof(c));
	for (int i = 0; i <= n; i++)
	{
		c[i][0] = 1;
		for (int j = 1; j <= i; j++)
			c[i][j] = c[i - 1][j - 1] + c[i - 1][j];
	}
}

int main()
{
	init(10);
	for (int n = 0, m = 0; ~scanf("%d%d", &n, &m); )
		printf("%d\n", c[n][m]);
	return 0;
}
