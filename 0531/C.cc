#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int maxn = int(1e3) + 5;
int a[maxn];

int main()
{
	int k, n; scanf("%d%d", &k, &n);
	for (int i = 0; i < n; i++)
	{
		int x; scanf("%d", &x);
		a[x]++;
	}
	if ((n - 1) % k == 0)
	{
		int d = (n - 1) / k, u = 0;
		for (int i = 1; i <= k; i++)
		{
			if (a[i] == d) continue;
			else if (a[i] - 1 == d && u == 0) u = i;
			else u = -1;
		}
		if (u == -1) puts("*");
		else printf("-%d\n", u);
	}
	else if ((n + 1) % k == 0)
	{
		int d = (n + 1) / k, u = 0;
		for (int i = 1; i <= k; i++)
		{
			if (a[i] == d) continue;
			else if (a[i] + 1 == d && u == 0) u = i;
			else u = -1;
		}
		if (u == -1) puts("*");
		else printf("+%d\n", u);
	}
	else if (n % k == 0)
	{
		int d = n / k, u = 0, v = 0;
		for (int i = 1; i <= k; i++)
		{
			if (a[i] == d) continue;
			else if (a[i] - 1 == d && u == 0) u = i;
			else if (a[i] + 1 == d && v == 0) v = i;
			else u = -1, v = -1;
		}
		if (u == -1) puts("*");
		else printf("-%d +%d\n", u, v);
	}
	else
		puts("*");
	return 0;
}
