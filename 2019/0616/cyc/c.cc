#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

typedef long long LL;

LL gcd(LL a, LL b) { return !b ? a : gcd(b, a % b); }

LL F(int n, int m)
{
	LL a = 1, b = 1, c = 1, d = 1;
	while (n--)
		a *= 5, b *= 7;
	while (m--)
		c *= 5, d *= 7;
	return gcd(a + b, c + d);
}

int main()
{
	int t;
	scanf("%d", &t);
	while (t--)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		puts(a % 2 == 0 || b % 2 == 0 ? "2" : "12");
	}
	return 0;
}
