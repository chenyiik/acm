#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

int a[15][15];

int f(int n, int m)
{
	int sum = 0, tot = 0;
	for (int i = 0; i < n; i++) for (int j = 0; j < m; j++)
	{
		if (a[i][j] < 0)
			tot++, a[i][j] *= -1;
		sum += a[i][j];
	}
	if (tot % 2 == 0)
		return sum;
	int minv = 0x7fffffff;
	for (int i = 0; i < n; i++) for (int j = 0; j < m; j++)
		minv = min(minv, a[i][j]);
	return sum - 2 * minv;
}

int main()
{
	int t; scanf("%d", &t);
	while (t--)
	{
		int n, m; scanf("%d%d", &n, &m);
		for (int i = 0; i < n; i++) for (int j = 0; j < m; j++)
			scanf("%d", &a[i][j]);
		printf("%d\n",f(n, m));
	}
	return 0;
}
