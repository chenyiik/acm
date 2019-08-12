#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int t;
	scanf("%d", &t);
	while (t--)
	{
		long long n, m, k;
		scanf("%lld%lld%lld", &n, &m, &k);
		if (m == 0)
			printf("%lld\n", k);
		else if (m < n - k + 1)
			printf("%lld\n", k + m);
		else
		{
			long long t = n;
			long long ans = 0x7ffffff;
			while (t >= max(k, n - 1000))
				ans = min(ans, 1 + m / (t - k + 1) * n), t--;
			printf("%lld\n", ans);
		}
	}
	return 0;
}
