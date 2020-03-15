#include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>

using namespace std;

typedef unsigned long long ULL;

int main()
{
	int n; scanf("%d", &n);
	while (n--)
	{
		ULL s; scanf("%llu", &s);
		ULL m = ULL(sqrt(s * 2));
		ULL ans = 0, tot = 0;
		for (ULL i = (m > 5 ? m - 5 : 0); i <= m + 5; i++)
		{
			ULL ss = i * (i + 1) / 2;
			if (ss <= s && ss > tot)
				ans = i, tot = ss;
		}
		printf("%llu\n", ans);
	}
	return 0;
}
