#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int maxn = int(1e5) + 5;
int a[maxn];

void solve() 
{
		int n; scanf("%d", &n);
		scanf("%d", &a[0]);
		if (n == 1)
		{
			puts("0");
			return;
		}
		int c = 0x7fffffff;
		for (int i = 1; i < n; i++)
		{
			scanf("%d", &a[i]);
			if (a[i] >= a[i - 1])
				c = min(c, a[i] - a[i - 1]);
		}
		int m = 0;
		if (c == 0x7fffffff)
		{
			for (int i = 1; i < n - 1; i++)
			{
				if (a[i] - a[i - 1] != a[i + 1] - a[i])
				{
					puts("-1");
					return;
				}
			}
			puts("0");
			return;
		}
		if (c == 0)
		{
			for (int i = 1; i < n; i++)
				if (a[i] != a[i - 1])
				{
					puts("-1");
					return;
				}
		}
		for (int i = 1; i < n; i++)
		{
			if (a[i] > a[i - 1])
			{
				if (a[i] - a[i - 1] == c)
					continue;
				else
				{
					puts("-1");
					return;
				}
			}
			else
			{
				if (m == 0)
					m = a[i - 1] + c - a[i];
				else if (a[i - 1] + c - a[i] == m)
					continue;
				else
				{
					puts("-1");
					return;
				}
			}
		}
		if (m == 0)
			puts("0");
		else if (m <= a[0])
			puts("-1");
		else
			printf("%d %d\n", m, c);
}

int main()
{
	int t; scanf("%d", &t);
	while (t--)
		solve();
	return 0;
}
