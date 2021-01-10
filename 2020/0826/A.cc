#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

typedef long long LL;

const int maxn = int(2e5) + 5, mod = int(1e9) + 7;
int a[maxn], s[maxn];

void init();
int inv(LL q);

int add(LL a, LL b) { return (a + b) % mod; }
int sub(LL a, LL b) { return (a % mod - b % mod + mod) % mod; } 
int mul(LL a, LL b) { return a * b % mod; }
int di(LL p, LL q) { return p * inv(q) % mod; }

int main()
{
	int _; scanf("%d", &_);
	init();
	while (_--)
	{
		int n; scanf("%d", &n);
		int ans = 0, tmp = 0, low = 1, high = n;
		for (int i = 1; i <= n; i++)
			scanf("%d", &s[i]);
		for (int i = 1, j = n; i <= (n + 1) / 2; i++, j--) 
		{
			tmp = add(tmp, sub(a[high], a[low - 1]));
			high--, low++;
			ans = add(ans, mul(s[i], tmp));
			if (i < j)
				ans = add(ans, mul(s[j], tmp));
		}
		ans = di(mul(ans, 2), mul(n, n + 1));
		printf("%d\n", ans);
	}
	return 0;
}

int pow_mod(LL a, LL p, LL n = mod)
{
	if (p == 0)
		return 1;
	LL ans = pow_mod(a, p / 2, n);
	ans = ans * ans % n;
	if (p % 2 == 1)
		ans = ans * a % n;
	return ans;
}

int inv(LL q) { return pow_mod(q, mod - 2); }

void init()
{
	for (int i = 1; i <= int(2e5); i++)
		a[i] = add(a[i - 1], inv(i));
}