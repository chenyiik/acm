#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int maxn = 105;
int a[maxn], p[maxn];

bool check(int n)
{
	for (int i = 1; i < n; i++)
		if (a[i] < a[i - 1])
			return false;
	return true;
}

int main()
{
	int t; scanf("%d", &t);
	while (t--)
	{
		int n, m; scanf("%d%d", &n, &m);
		for (int i = 0; i < n; i++)
			scanf("%d", &a[i]);
		for (int i = 0; i < m; i++)
			scanf("%d", &p[i]);
		sort(p, p + m);
		int l = 0, r = 0;
		for (int i = 0; i < m; i++)
		{
			if (p[i] != r + 1)
			{
				sort(a + l, a + r + 1);
				l = p[i] - 1;
			}
			r = p[i];
		}
		sort(a + l, a + r + 1);
		puts(check(n) ? "YES" : "NO");
	}
	return 0;
}
