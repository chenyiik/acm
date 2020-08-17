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
		int i = 0;
		while (a < b && ++i < 1000)
		{
			if (a % 2 == 0)
				a = a / 2 * 3;
			else if (a > 1)
				a--;
		}
		puts(a >= b ? "YES" : "NO");
	}
	return 0;
}
