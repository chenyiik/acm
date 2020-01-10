#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

typedef long long LL;

const LL mod = int(1e9) + 7, maxn = int(5e5) + 5;

LL dp[maxn], sum[maxn];

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

int main()
{
	int t;
	scanf("%d", &t);
	while (t--)
	{
		int n, q;
		scanf("%d%d", &n, &q);
		for (int i = 0; i <= n; i++)
			dp[i] = sum[i] = 0;
		for (int i = 1; i <= n; i++)
		{
			long long r, s, x, a;
			scanf("%lld%lld%lld%lld", &r, &s, &x, &a);
			dp[i] = ((s - r) * (a + sum[i - 1] - sum[x - 1] + mod) % mod * inv(r) + a) % mod;
			sum[i] = (sum[i - 1] + dp[i]) % mod;
		}
		while (q--)
		{
			int l, r;
			scanf("%d%d", &l, &r);
			printf("%lld\n", (sum[r - 1] - sum[l - 1] + mod) % mod);
		}
	}
	return 0;
}
