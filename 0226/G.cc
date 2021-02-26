#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

typedef long long LL;
LL a[3] = {8, 10, 12};

const LL mod = LL(1e9) + 7;

LL pow_mod(LL a, LL p, LL n = mod)
{
	if (p == 0)
		return 1;
	LL ans = pow_mod(a, p / 2, n);
	ans = ans * ans % n;
	if (p % 2 == 1)
		ans = ans * a % n;
	return ans;
}

int main()
{
	LL n; scanf("%lld", &n); --n;
	printf("%lld\n", (a[n % 3] * pow_mod(2, n / 3) - 7 + mod) % mod);
	return 0;
}

