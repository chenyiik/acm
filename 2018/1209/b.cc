#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

int check(int *be, int *en, long long mid)
{
	int ans = 0;
	for (int *p = be; p < en; p++)
	{
		if (*p <= mid)
		{
			mid -= *p;
			ans++;
		}
	}
	return ans;
}

int main()
{
	int t = 0;
	scanf("%d", &t);
	while (t--)
	{
		const int N = static_cast<int>(1e5) + 5;
		static int a[N];
		int nn = 0, m = 0;
		scanf("%d%d", &nn, &m);
		if (nn == m)
		{
			puts("Richman");
			while (nn--)
				scanf("%*d");
			continue;
		}
		int n = 0;
		for (int i = 0; i < nn; i++)
		{
			scanf("%d", &a[n]);
			if (a[n] == 0)
				m--;
			else
				n++;
		}
		if (m < 0)
		{
			puts("Impossible");
			continue;
		}
		long long ans = 0;
		for (int i = 0; i < m; i++)
			ans += a[i];
		int add = static_cast<int>(1e9);
		for (int i = m; i < n; i++)
			add = min(add, a[i] - 1);
		printf("%lld\n", ans + add);
		/*
		long long l = 0, r = static_cast<long long>(1e15) + 1LL;
		while (l < r - 1)
		{
			long long mid = (l + r) / 2;
			if (check(a, a + n, mid) <= m)
				l = mid;
			else
				r = mid;
		}
		if (check(a, a + n, l) == m)
			printf("%lld\n", l);
		else
			puts("Impossible");
		 */
	}
	return 0;
}
