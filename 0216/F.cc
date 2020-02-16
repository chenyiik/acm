#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int t; scanf("%d", &t);
	while (t--)
	{
		long long a, b; scanf("%lld%lld", &a, &b);
		long long c = a - b;
		printf("%lld\n", c / 6 + int(c % 6 > 0));
	}
	return 0;
}
