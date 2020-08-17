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
		const unsigned long long e = 1LL << 62;
		unsigned long long a, b, c, d;
		scanf("%llu%llu%llu%llu", &a, &b, &c, &d);
		if (a == e && b == e && c == e && d == e)
		{
			puts("18446744073709551616");
			continue;
		}
		printf("%llu\n", a + b + c + d);
	}
	return 0;
}
