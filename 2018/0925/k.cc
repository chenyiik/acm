#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

long long f[10007];

void init(int n)
{
	f[1] = 2;
	for (int i = 2; i < n; i++)
		f[i] = f[i - 1] + 4LL * (i - 1) + 1LL;
}

int main()
{
	init(10003);
	int t = 0;
	scanf("%d", &t);
	while (t--)
	{
		int n = 0;
		scanf("%d", &n);
		printf("%lld\n", f[n]);
	}
	return 0;
}
