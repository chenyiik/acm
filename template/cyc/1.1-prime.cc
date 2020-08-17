#include "cyc.h"

const int maxn = 10000000 + 10, maxp = 700000;
bool is_p[maxn]; //is_p[i] == true when i is 1 or a prime
int prime[maxp], pn = 0;

void prime_table(int n)
{
	for (int i = 2; i <= n; i++)
	{
		if (!is_p[i])
			prime[pn++] = i;
		for (int j = 0; j < pn && i * prime[j] <= n; j++)
		{
			is_p[i * prime[j]] = true;
			if (i % prime[j] == 0)
				break;
		}
	}
}
