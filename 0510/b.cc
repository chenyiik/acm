#include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

typedef long long LL;

const int maxN = static_cast<int>(1e7) + 7;
bool vis[maxN];
set<int> S;
int fucked[1000], N = 0;

void sieve(int n)
{
	int m = (int)sqrt(n + 0.5);
	for (int i = 2; i <= m; i++)
		if (!vis[i])
			for (int j = i * i; j <= n; j += i)
				vis[j] = true;
}

int gen_primes(int n = (int)sqrt(10000000 + 0.5))
{
	sieve(n);
	for (int i = 2; i <= n; i++)
		if (!vis[i])
			S.insert(i);
	return S.size();
}

void fuck(int n)
{
	for (int i : S)
	{
		if (n % i == 0)
			S.remove(i);
		fucked[N++] = i;
	}
}

int main()
{
	gen_primes();
	memset(vis, false, sizeof(vis));
	LL a, b, c, d;
	scanf("%lld%lld%lld%lld", &a, &b, &c, &d);
	LL ans = (b - a + 1) * (d - c + 1);
	for (int i = c; i <= d; i++)
		fuck(i);
	for (int i = 0; i < N; i++)
	{
	}
	return 0;
}
