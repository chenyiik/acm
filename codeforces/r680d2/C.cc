#include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>

using namespace std;

typedef long long LL;

const int maxm = int(1e5) + 1;
int prime[maxm], n = 0;
void gen_prime();

LL g(LL a, LL b, LL p)
{
	while (a % b == 0 && a % p == 0) a /= p;
	return a % b != 0 ? a : -1;
}

LL f(LL a, LL b)
{
	if (a % b != 0) return a;
	LL ans = 0, num = b;
	for (int i = 0; i < n && prime[i] <= num; i++) 
		if (num % prime[i] == 0)
		{
			ans = max(ans, g(a, b, prime[i]));
			while (num % prime[i] == 0)
				num /= prime[i];
		}
	if (num > 1)
		ans = max(ans, g(a, b, num));
	return ans;
}

int main()
{
	gen_prime();
	int _; scanf("%d", &_);
	while (_--)
	{
		long long a; int b; scanf("%lld%d", &a, &b);
		printf("%lld\n", f(a, b));
	}
	return 0;
}

bool no_prime[maxm];
void gen_prime()
{
	int m = sqrt(maxm) + 1e-9;
	for (int i = 2; i < m; i++) if (!no_prime[i])
	{
		prime[n++] = i;
		for (int j = i * i; j < maxm; j += i)
			no_prime[j] = true;
	}
	for (int i = m; i < maxm; i++) if (!no_prime[i])
		prime[n++] = i;
}
