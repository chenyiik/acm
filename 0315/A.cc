#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

typedef unsigned long long ULL;

const int maxn = int(1e7);
ULL f[maxn];
const int mod = int(1e9) + 7;

int main()
{
	int n; scanf("%d", &n);
	if (n % 2 == 1)
		return puts("0"), 0;
	ULL sum = f[0] = 1;
	for (int i = 2; i <= n; i += 2)
		f[i] = (f[i - 2] + sum * 2) % mod, sum = (sum + f[i]) % mod;
	printf("%llu\n", f[n]);
	return 0;
}
