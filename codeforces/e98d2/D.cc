#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int maxn = int(2e5) + 1, mod = 998244353;
int f[maxn];
void init()
{
	f[1] = 1;
	for (int i = 2; i < maxn; i++)
		f[i] = (f[i - 1] + f[i - 2]) % mod;
}

int pow_mod(int a, int p)
{
	if (p == 0) return 1;
	long long ans = pow_mod(a, p / 2);
	ans = ans * ans % mod;
	if (p % 2 == 1) ans = ans * a % mod;
	return ans;
}

int inv(int a) { return pow_mod(a, mod - 2); }

int main()
{
	init();
	int n; scanf("%d", &n);
	printf("%lld\n", (long long)f[n] * inv(pow_mod(2, n)) % mod);
	//cout << f[n] << ' ' << pow_mod(2, n) << endl;
	return 0;
}
