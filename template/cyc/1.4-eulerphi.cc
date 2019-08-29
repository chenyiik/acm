#include "cyc.h"

int euler_phi(int n)
{
	int m = (int)sqrt(n + 0.5);
	int ans = n;
	for (int i = 2; i <= m; i++)
		if (n % i == 0)
		{
			ans = ans / i * (i - 1);
			while (n % i == 0)
				n /= i;
		}
	if (n > 1)
		ans = ans / n * (n - 1);
	return ans;
}

const int maxn = 10000000 + 10;
int phi[maxn], prime[int(7e5)], pn = 0;
bool is_p[maxn + 5];

void phi_table(int n)
{
	phi[1] = 1;
	for (int i = 2; i <= n; i++)
		phi[i] = 0;
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
}
