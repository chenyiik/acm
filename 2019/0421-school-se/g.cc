#include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>

using namespace std;

typedef long long LL;

LL is_prime(LL n)
{
	if (n < 2)
		return false;
	LL m = (LL)sqrt(n + 0.5);
	for (LL i = 2; i <= m; i++)
		if (n % i == 0)
			return false;
	return true;
}

LL euler_phi(LL n)
{
	LL m = (LL)sqrt(n + 0.5);
	LL ans = n;
	for (LL i = 2; i <= m; i++)
		if (n % i == 0)
		{
			ans = ans / i * (i - 1);
			while (n % i == 0)
				n /= i;
		}
	if (n > 1)
		ans = ans / n * (n - 1);
	return ans;
}

int main()
{
	const LL n = 300;
	static LL a[n];
	for (LL i = 0; i < n; i++)
		scanf("%lld", &a[i]);
	for (LL i = 0; i < n; i++)
	{
		LL m = a[i] + 1;
		if (!is_prime(m))
			continue;
		LL st = max(1LL, m - i);
		if (st + 300 > 1LL + static_cast<LL>(1e9))
			continue;
		bool b = true;
		for (LL j = 0; j < n; j++)
		{
			if (euler_phi(st + j) != a[j])
			{
				b = false;
				break;
			}
		}
		if (b)
			return printf("%lld\n", st), 0;
	}
	puts("yang12138 laji");
	return 0;
}
