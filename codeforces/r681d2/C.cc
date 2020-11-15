#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <utility>

using namespace std;

typedef long long LL;

const int maxn = int(2e5) + 5;
pair<LL, LL> a[maxn];

LL solve(int n)
{
	LL ans = 0;
	for (int i = n - 1; i >= 0; i--)
	{
		if (ans + a[i].second < a[i].first)
			ans += a[i].second;
		else
			return max(ans, a[i].first);
	}
	return ans;
}

int main()
{
	int _; scanf("%d", &_);
	while (_--)
	{
		int n; scanf("%d", &n);
		for (int i = 0; i < n; i++) scanf("%lld", &a[i].first);
		for (int i = 0; i < n; i++) scanf("%lld", &a[i].second);
		sort (a, a + n);
		printf("%lld\n", solve(n));
	}
	return 0;
}
