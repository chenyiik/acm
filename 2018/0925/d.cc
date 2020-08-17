#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

int c[40][40];

void init(int n)
{
	memset(c, 0, sizeof(c));
	c[1][1] = 1;
	for (int i = 2; i < n; i++)
	{
		for (int j = 1; j <= i; j++)
			c[i][j] = c[i - 1][j - 1] + c[i - 1][j];
	}
}

int main()
{
	init(35);
	int n = 0;
	while (~scanf("%d", &n))
	{
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= i; j++)
			{
				printf("%d", c[i][j]);
				printf(j == i ? "\n" : " ");
			}
		}
		printf("\n");
	}
	return 0;
}
