#include "cyc.h"

const int maxn = 100000 + 10;
int C[maxn], n; //from 1 to n

int lowbit(int x) { return x & -x; }

int sum(int x)
{
	int ret = 0;
	while (x > 0)
	{
		ret += C[x];
		x -= lowbit(x);
	}
	return ret;
}

void add(int x, int d)
{
	while (x <= n)
	{
		C[x] += d;
		x += lowbit(x);
	}
}
