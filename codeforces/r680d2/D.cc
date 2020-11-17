#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int maxn = int(3e5) + 5, mod = 998244353;
int a[maxn];

typedef long long LL;

LL pow_mod(LL a, LL b)
{
	if (b == 0) return 1;
	LL tmp = pow_mod(a, b / 2), ans = tmp * tmp % mod;
	if (b % 2 == 1) ans = ans * a % mod;
	return ans;
}

LL inv(LL a) { return pow_mod(a, mod - 2); }

int main()
{
	int n; scanf("%d", &n);
	LL c = 1;
	for (int i = 0; i < n; i++)
	{
		c = c * (2 * n - i) % mod;
		c = c * inv(i + 1) % mod;
	}
	for (int i = 0; i < n * 2; i++)
		scanf("%d", &a[i]);
	sort(a, a + n + n);
	LL count = 0;
	for (int i = 0; i < n; i++)
	{
		int j = 2 * n - i - 1;
		count += a[j] - a[i];
	}
	printf("%lld\n", count % mod * c % mod);
	return 0;
}
