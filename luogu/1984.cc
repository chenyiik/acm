#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

typedef long long LL;

LL gcd(LL a, LL b) { return !b ? a : gcd(b, a % b); }

int main()
{
	int n = 0;
	scanf("%d", &n);
	double cnt = 4200.0 * 100 / n, ans = 0.0;
	for (int i = 1; i <= n; i++)
	{
		ans += cnt;
		cnt *= (i * 2.0 - 1) / i / 2;
	}
	printf("%.2f", ans);
	return 0;
}
