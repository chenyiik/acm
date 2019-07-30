#include <cstdio>
#include <cstring>
#include <iostream>

int a[100], b[100], c[100];
const long long base = 10, width = 1, hry_base = 30;

int main()
{
	int t = 0;
	scanf("%d", &t);
	while (t--)
	{
		int n = 0;
		scanf("%d", &n);
		long long sa = 0;
		for (int i = 0; i < n; i++)
		{
			int x = 0;
			scanf("%d", &x);
			sa += x;
		}
		long long sb = 0;
		for (int i = 0; i < n; i++)
		{
			int x = 0;
			scanf("%d", &x);
			sb += x;
		}
		long long hry = sa * sb;
		memset(a, 0, sizeof(a));
		int m = hry_base;
		while (hry)
		{
			a[m] = hry % base;
			hry /= base;
			m++;
		}
		memset(c, 0, sizeof(c));
		for (int i = m - 1; i >= 1; i--)
		{
			c[i] = a[i] / n;
			a[i - 1] += a[i] % n * 10;
		}
		c[0] = a[0] / n;
		a[0] = a[0] % n;
		if (a[0] * 2 >= n)
			c[0]++;
		int p = 0;
		while (c[p] >= 10)
		{
			c[p] -= 10;
			c[++p]++;
		}
		while (m > 30 && c[m] == 0)
			m--;
		for (int i = m; i >= 30; i--)
			printf("%d", c[i]);
		putchar('.');
		for (int i = 29; i >= 0; i--)
			printf("%d", c[i]);
		puts("");
	}
	return 0;
}
