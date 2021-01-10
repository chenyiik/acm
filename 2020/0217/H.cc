#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

typedef long long LL;

int main()
{
	int t; scanf("%d", &t);
	while (t--)
	{
		LL n; scanf("%lld", &n);
		LL sum = 0;
		for (LL p = 2, q = 1, i = 1; p <= n; p *= 2, q *= 2, i++)
		{
			LL d = n / p;
			sum += d * q * i;
		}
		printf("%lld\n", sum);
	}
	return 0;
}
