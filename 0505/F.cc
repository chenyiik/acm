#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <utility>

using namespace std;

typedef long long LL;

const int maxn = 1005;
pair<LL, int> a[maxn];
int ans[maxn];

bool check(int m, __int128 y)
{
	for (int i = 1; i <= m; i++)
		if (i * y >= a[i].first)
			return false;
	return true;
}

LL solve(int m)
{
	__int128 l = 0, r = LL(1e18) + 10;
	while (l + 1 < r)
	{
		__int128 mid = (l + r) / 2;
		if (check(m, mid))
			l = mid;
		else
			r = mid;
	}
	return l + 1;
}

int main()
{
	int n; scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%lld", &a[i].first);
		a[i].second = i;
	}

	int rk = 1, m = n;
	while (m > 0)
	{
		LL y = solve(m);
		int p = 0;
		for (int i = 1; i <= m + p; i++)
		{
			a[i].first -= i * y - p;
			if (a[i].first <= 0)
			{
				ans[rk++] = a[i].second;
				m--, p++;
			}
			else
				a[i - p] = a[i];
		}
	}

	for (int i = 1; i <= n; i++)
		printf("%d%c", ans[i], " \n"[i == n]);

	return 0;
}
