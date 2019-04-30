#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

typedef long long LL;

int main()
{
	LL n = 0, ans = 1;
	scanf("%lld", &n);
	LL two = 0, five = 0;
	for (LL i = 1; i <= n; i++)
	{
		LL x = i;
		while (x % 2 == 0)
			two++, x /= 2;
		while (x % 5 == 0)
			five++, x /= 5;
		ans = ans * x % 10;
	}
	while (two > five)
		ans = ans * 2 % 10, two--;
	while (five > two)
		ans = ans * 5 % 10, five--;
	printf("%lld\n", ans);
	return 0;
}
