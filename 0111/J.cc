#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

long long gcd(long long a, long long b) { return !b ? a : gcd(b, a % b); }
long long lcm(long long a, long long b) { return a / gcd(a, b) * b; }

long long a[1005];

int main()
{
	long long n, m;
	while (~scanf("%lld%lld", &n, &m))
	{
		long long lc = 1;
		for (int i = 0; i < n; i++)
		{
			scanf("%lld", &a[i]);
			lc = lcm(lc, a[i]);
		}
		long long sum = 0;
		for (int i = 0; i < n; i++)
			sum += lc / a[i];
		if (m % sum != 0)
		{
			puts("No");
			continue;
		}
		puts("Yes");
		long long c = m / sum;
		for (int i = 0; i < n; i++)
			printf("%lld%c", lc / a[i] * c, " \n"[i + 1 == n]);
	}
	return 0;
}
