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
		int n = 0;
		long long a = 0, b = 0, c = 0;
		scanf("%d%lld%lld%lld", &n, &a, &b, &c);
		n %= 4;
		if (n == 0)
			puts("0");
		else if (n == 1)
			printf("%lld\n", min(a * 3, min(a + b, c)));
		else if (n == 2)
			printf("%lld\n", min(a * 2, min(b, c * 2)));
		else
			printf("%lld\n", min(a, min(b + c, c * 3)));
	}
	return 0;
}
