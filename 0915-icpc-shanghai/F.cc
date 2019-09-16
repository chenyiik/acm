#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

typedef unsigned long long LL;

LL f[200][30];
void init()
{
	for (char c = 'A'; c <= 'Z'; c++)
		f[c][1] = 1;
	for (int i = 2; i <= 26; i++)
		for (char c = 'A'; c <= 'Z' - i + 1; c++)
		{
			f[c][i] = f[c][i - 1] * (c - 'A' + 1) + f[c + 1][i - 1];
			printf("%lld\n", f[c][i]);
		}
}

LL solve(LL n, LL k)
{
}

int main()
{
	init();
	int __; scanf("%d", &__);
	for (int _ = 1; _ <= __; _++)
	{
		LL n, k; scanf("%lld%lld", &n, &k);
		printf("Case %d: %lld\n", _, solve(n, k));
	}
	return 0;
}
