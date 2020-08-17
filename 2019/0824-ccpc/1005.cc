#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

typedef long long LL;

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

LL inv(LL a, LL n = mod) { return pow_mod(a, n - 2, n); }
const LL inv2 = inv(2), inv6 = inv(6);
const int maxn = 5000000;

LL s[maxn + 5];
unordered_map<int, LL> M;

void init()
{
	static int prime[int(7e5)], pn = 0;
	static bool is_p[maxn + 5];
	LL *phi = s;
	phi[1] = 1;
	for (int i = 2; i <= maxn; i++)
	{
		if (!is_p[i])
		{
			prime[pn++] = i;
			phi[i] = i - 1;
		}
		for (int j = 0; j < pn && i * prime[j] <= maxn; j++)
		{
			is_p[i * prime[j]] = true;
			if (i % prime[j] == 0)
				phi[i * prime[j]] = phi[i] * prime[j], j = pn;
			else
				phi[i * prime[j]] = phi[i] * (prime[j] - 1);
		}
	}
	for (int i = 2; i <= maxn; i++)
		s[i] = (s[i] * i % mod + s[i - 1]) % mod;
}

LL S(LL n)
{
	if (n <= maxn)
		return s[n];
	if (M.find(n) != M.end())
		return M[n];
	M[n] = n * (n + 1) % mod * (n * 2 + 1) % mod * inv6 % mod;
	for (LL l = 2, r; l <= n; l = r + 1)
	{
		r = n / (n / l);
		LL sum = (l + r) * (r - l + 1) / 2 % mod;
		LL sub = sum * S(n / l) % mod;
		M[n] = (M[n] - sub + mod) % mod;
	}
	return M[n];
}

int main()
{
	init();
	int _; scanf("%d", &_);
	while (_--)
	{
		LL n; scanf("%lld%*d%*d", &n);
		printf("%lld\n", (S(n) - 1 + mod) % mod * inv2 % mod);
	}
	return 0;
}
