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
		long long n = 0;
		scanf("%lld", &n);
		long long ans = 0;
		while (n)
			ans += n /= 2;
		printf("%lld\n", ans);
	}
	return 0;
}
