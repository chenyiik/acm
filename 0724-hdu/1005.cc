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
LL a[maxn], c[maxn][maxn], ans[maxn], tot[maxn];

void init()
{
	LL iv4 = inv(4);
	for (LL i = 1; i < maxn; i++)
		a[i] = i * (i - 1) * iv4 % mod;
	for (int i = 0; i < maxn; i++)
	{
		c[i][0] = 1;
		for (int j = 1; j <= i; j++)
			c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % mod;
	}
	for (int k = 1; k < maxn; k++)
	{
		LL &kk = ans[k];
		for (int i = 0; i < k; i++)
			kk = (kk + c[k][i] * a[k - i] % mod) % mod;
		kk = kk * inv((pow_mod(2, k) + mod - 1) % mod) % mod;
		kk = (kk + a[k]) % mod;
	}
	for (int i = 1; i < maxn; i++)
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
