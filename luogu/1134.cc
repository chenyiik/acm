#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	long long n = 0, ans = 1;
	scanf("%lld", &n);
	for (long long i = 1; i <= n; i++)
	{
		ans *= i;
		while (ans % 10 == 0)
			ans /= 10;
		ans %= 1000;
	}
	printf("%lld\n", ans % 10);
	return 0;
}
