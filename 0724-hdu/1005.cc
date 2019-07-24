#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

typedef long long LL;

const LL mod = 998244353LL;

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

LL inv(LL a, LL n = mod) { return pow_mod(a, n - 2, n); }

const int maxn = 3000;
LL dd[maxn + 1];

int main()
{
	LL n;
	while (~scanf("%lld", &n))
	{
		LL ans = 2 * pow_mod(n - 1, 2) * inv(3) % mod * inv(n) % mod;
		printf("%lld\n", ans);
	}
	return 0;
}
