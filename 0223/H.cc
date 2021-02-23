#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int bit = 20;
int mp[1 << bit];
void init();

const int maxm = int(12e4) / bit + 5;
int nx, ny, nz;
unsigned a[maxm], b[maxm];
long long solve(int mov);

int main()
{
	init();
	scanf("%d", &nx);
	for (int i = 0; i < nx; i++)
	{
		int t; scanf("%d", &t); t += int(3e4);
		a[t / bit] |= 1 << (t % bit);
	}
	scanf("%d", &ny);
	for (int i = 0; i < ny; i++)
	{
		int t; scanf("%d", &t); t = 2 * (t + int(3e4));
		b[t / bit] |= 1 << (t % bit);
	}
	long long ans = 0;
	scanf("%d", &nz);
	for (int i = 0; i < nz; i++)
	{
		int t; scanf("%d", &t); t += int(3e4);
		ans += solve(t);
	}
	printf("%lld\n", ans);
	return 0;
}

long long solve(int mov)
{
	static unsigned d[maxm];
	memset(d, 0, sizeof(d));
	long long ret = 0;
	int offset = mov / bit;
	for (int i = maxm - 1; i >= offset; i--)
		d[i] = a[i - offset];
	offset = mov % bit;
	for (int i = maxm - 1; i >= 0; i--)
	{
		d[i] <<= offset;
		d[i] &= (1 << bit) - 1;
		if (i > 0)
			d[i] |= d[i - 1] >> (bit - offset);
	}
	for (int i = 0; i < maxm; i++)
	{
		int k = b[i] & d[i];
		ret += mp[k];
	}
	return ret;
}

void init()
{
	for (int i = 0; i < (1 << 20); i++)
	{
		int t = i;
		while (t)
		{
			if (t & 1)
				mp[i]++;
			t >>= 1;
		}
	}
}
