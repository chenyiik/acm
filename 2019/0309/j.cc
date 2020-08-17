#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;

ll gcd(ll a, ll b) { return !b ? a : gcd(b, a % b); }

int main()
{
	int t = 0;
	scanf("%d", &t);
	for (int i = 1; i <= t; i++)
	{
		int n = 0;
		scanf("%d", &n);
		static ll a[15], b[15];
		for (int i = 0; i < n; i++)
			scanf("%lld", &a[i]);
		for (int i = 0; i < n; i++)
			scanf("%lld", &b[i]);
		ll aa = 1, bb = 0;
		for (int i = n - 1; i >= 0; i--)
		{
			ll aaa = a[i] * aa + bb, bbb = b[i] * aa;
			aa = aaa, bb = bbb;
			ll t = gcd(aa, bb);
			aa /= t;
			bb /= t;
		}
		printf("Case #%d: %lld %lld\n", i, bb, aa);
	}
	return 0;
}
