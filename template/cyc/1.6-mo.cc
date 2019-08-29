#include "cyc.h"

const int maxn = 10000000 + 10, maxp = 700000;
bool is_p[maxn]; //is_p[i] == true when i is 1 or a prime
int mo[maxn], prime[maxp], pn = 0;

void prime_table(int n)
{
	mo[1] = 1;
	for (int i = 2; i <= n; i++)
	{
		if (!is_p[i])
		{
			prime[pn++] = i;
			mo[i] = -1;
		}
		for (int j = 0; j < pn && i * prime[j] <= n; j++)
		{
			is_p[i * prime[j]] = true;
			if (i % prime[j] == 0)
				break;
			else
				mo[i * prime[j]] = -mo[i];
		}
	}
}
