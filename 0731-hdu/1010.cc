#include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>

using namespace std;

typedef long long LL;

const int maxn = int(1e6) + 10;
const int maxp = int(1e5) + 10;

int vis[maxn];
LL prime[maxp], *a = prime;

void sieve(int n)
{
	int m = int(sqrt(n + 0.5));
	memset(vis, 0, sizeof(vis));
	for (int i = 2; i <= m; i++)
		if (!vis[i])
			for (int j = i * i; j <= n; j += i)
				vis[j] = 1;
}

int gen_primes(int n)
{
	sieve(n);
	int c = 0;
	for (int i = 2; i <= n; i++)
		if (!vis[i])
			prime[c++] = i;
	return c;
}

int m;

int f(LL n)
{
	if (n <= 1e6 && !vis[n])
		return 1;
	int ans = 0x7fffffff;
	for (int i = 0; n > 1 && i < m; i++)
		if (n % a[i] == 0)
		{
			int tmp = 0;
			while (n % a[i] == 0)
				tmp++, n /= a[i];
			ans = min(ans, tmp);
			if (ans == 1)
				return ans;
		}
	if (n == 1)
		return ans;
	LL k = (LL)sqrt(n + 0.5);
	return k * k == n ? 2 : 1;
}

int main()
{
	m = gen_primes(int(32000));
	//cout << m << endl;
	int t;
	scanf("%d", &t);
	while (t--)
	{
		LL n;
		scanf("%lld", &n);
		printf("%d\n", f(n));
	}
	return 0;
}
