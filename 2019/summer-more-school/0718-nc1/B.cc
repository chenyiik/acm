#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;

const int maxn = 1005, mod = int(1e9) + 7;
ll a[maxn];

ll pow_mod(ll a, ll p, ll n)
{
	if (p == 0)
		return 1;
	ll ans = pow_mod(a, p / 2, n);
	ans = ans * ans % n;
	if (p % 2 == 1)
		ans = ans * a % n;
	return ans;
}
ll inv(ll a, ll n = mod) { return pow_mod(a, n - 2, n); }

int main()
{
	int n;
	while (~scanf("%d", &n))
	{
		for (int i = 0; i < n; i++)
			scanf("%lld", &a[i]);
		ll ans = 0;
		for (int i = 0; i < n; i++)
		{
			ll tmp = 2 * a[i] % mod;
			for (int j = 0; j < n; j++) if (j != i)
			{
				ll ump = (a[j] * a[j] - a[i] * a[i]) % mod;
				if (ump < 0)
					ump += mod;
				tmp = tmp * ump % mod;
			}
			ans = (ans + inv(tmp)) % mod;
		}
		printf("%lld\n", ans);
	}
	return 0;
}
