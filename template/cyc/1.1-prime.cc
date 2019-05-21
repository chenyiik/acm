#include "cyc.h"

const int maxn = 10000000 + 10;
const int maxp = 700000;

int vis[maxn]; //vis[i] == 0 when i is 1 or a prime
int prime[maxp];

void sieve(int n)
{
	int m = (int)sqrt(n + 0.5);
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
