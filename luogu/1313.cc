#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;
typedef long long LL;

void gcd(LL a, LL b, LL &d, LL &x, LL &y)
{
	if (!b)
		d = a, x = 1, y = 0;
	else 
		gcd(b, a % b, d, y, x), y -= x * (a / b);
}

LL inv(LL a, LL n)
{
	LL d, x, y;
	gcd(a, n, d, x, y);
	return d == 1 ? (x + n) % n : -1;
}

const int mod = 10007;

LL pow_mod(LL a, LL p, LL n)
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
	LL a, b, k, n, m;
	scanf("%lld%lld%lld%lld%lld", &a, &b, &k, &n, &m);
	a = pow_mod(a, n, mod);
	b = pow_mod(b, m, mod);
	LL ans = 1;
	for (int i = 1, j = k; i <= min(n, m); i++, j--)
	{
		int d = inv(i, mod);
		ans = ans * j * d % mod;
	}
	printf("%lld", ans * a * b % mod);
	return 0;
}
