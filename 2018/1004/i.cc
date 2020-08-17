#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	static int a[static_cast<int>(1e5) + 7];
	int l = 0, n = 0;
	scanf("%d%d", &l, &n);
	for (int i = 0; i < n ; i++)
		scanf("%d", &a[i]);
	int minp = a[0] * 2, maxp = (l - a[n - 1]) * 2;
	for (int i = 0; i < n; i++)
	{
		if (a[i] >= minp)
		{
			minp = a[i];
			break;
		}
	}
	for (int i = n - 1; i >= 0; i--)
	{
		if (a[i] <= (l - maxp))
		{
			maxp = (l - a[i]);
			break;
		}
	}
	printf("%d\n", min(l, minp + maxp));
	return 0;
}
/*
int main()
{
	int l = 0, n = 0;
	scanf("%d%d", &l, &n);
	static int a[static_cast<int>(1e5) + 7];
	a[0] = 0, a[n + 1] = l;
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	int minp = a[1] * 2, maxp = l - (l - a[n]) * 2;
	int p = lower_bound(a, a + n + 2, minp) - a;
	minp = p == n + 2 ? a[n + 1] : a[p];
	p = upper_bound(a, a + n + 2, maxp) - a - 1;
	maxp = p == -1 ? a[0] : a[p];
	printf("%d\n", min(l, minp + l - maxp));
	return 0;
}
*/
