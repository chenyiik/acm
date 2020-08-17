#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int t;
	scanf("%d", &t);
	while (t--)
	{
		long long n, m, k;
		scanf("%lld%lld%lld", &n, &m, &k);
		printf("%lld\n", (1 + m / (n - k + 1)) * (k - 1) + m + 1);
	}
	return 0;
}
