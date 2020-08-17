#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

typedef long long LL;

int main()
{
	int t; scanf("%d", &t);
	while (t--)
	{
		LL n; scanf("%lld", &n);
		printf("%lld\n", (n * (n + 1)) ^ (n + 1));
	}
	return 0;
}
