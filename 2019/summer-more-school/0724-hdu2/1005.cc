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

const int maxn = 3000 + 1;
LL c[maxn][maxn], ans[maxn], tot[maxn];

LL f(LL i)
{
	if (ans[i] > -1) return ans[i];
	LL p = i * (i - 1) * pow_mod(2, i - 2) % mod;
	for (int j = 1; j < i; j++)
		p = (p + c[i][j] * f(j)) % mod;
	LL q = inv((pow_mod(2, i) - 1 + mod) % mod);
	return ans[i] = p * q % mod;
}

void init()
{
	for (int i = 0; i < maxn; i++)
	{
		c[i][0] = 1;
		for (int j = 1; j <= i; j++)
			c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % mod;
	}
	memset(ans, -1, sizeof(ans));
	ans[0] = ans[1] = 0, f(3000);
	for (int i = 1; i <= 3000; i++)
		tot[i] = (tot[i - 1] + ans[i]) % mod;
}

int main()
{
	init();
	LL n;
	while (~scanf("%lld", &n))
		printf("%lld\n", tot[n] * inv(n) % mod);
	return 0;
}
