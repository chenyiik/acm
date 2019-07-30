#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int t = 0;
	scanf("%d", &t);
	while (t--)
	{
		long long a = 0, b = 0, k = 0;
		scanf("%lld%lld%lld", &a, &b, &k);
		b = a - b;
		printf("%lld\n", (k / 2) * b + (k % 2) * a);
	}
	return 0;
}
