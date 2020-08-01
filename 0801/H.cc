#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

typedef long long LL;
const LL mod = int(1e9) + 7;

LL divsum(LL n, LL k)
{
	if (k > n) k = n;
	LL ans = 0;
	for (LL i = 1; i <= k; i++)
	{
		LL p = n / i, q = min(k, n / p);
		ans += p * (q - i + 1);
		ans %= mod;
		i = q;
	}
	return ans;
}

int main()
{
	LL n, k; scanf("%lld%lld", &n, &k);
	//printf("%lld\n", divsum(n, k));
	printf("%lld\n", (divsum(n, k) + divsum(n - 1, k) + k - n % mod + mod) % mod);
	return 0;
}


void test() 
{
	const int maxn = 100;
	static bool vis[maxn];
	int k = 7; vis[1] = true;
	for (int i = 1; i < maxn; i++) if (vis[i])
	{
		cout << i << ' ';
		if (i + k < maxn) vis[i + k] = true;
		if (k * k < maxn) vis[i * k] = true;
	}
	cout << endl;
}
