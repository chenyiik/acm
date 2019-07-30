#include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>

using namespace std;
typedef long long LL;

LL sum(LL a, LL d, LL n) { return a * n + n * (n - 1) * d / 2; }

int main()
{
	LL n, k, ans = 0;
	scanf("%lld%lld", &n, &k);
	int sq = (int)sqrt(k + 0.5);
	for (int i = 1; i <= sq; i++)
	{
		LL l = k / (i + 1), r = k / i;
		ans += sum(k % r, i, r - l);
	}
	for (int i = 1; i <= k / (sq + 1); i++)
		ans += k % i;
				
	if (n >= k)
		ans += (n - k) * k;
	else
	{
		for (int i = 1; i <= sq; i++)
		{
			LL l = k / (i + 1), r = k / i;
			if (l >= n)
				ans -= sum(k % r, i, r - l);
			else
			{
				ans -= sum(k % r, i, r - n);
				break;
			}
		}
		for (int i = k / (sq + 1); i > n; i--)
			ans -= k % i;
	}
	printf("%lld\n", ans);
	LL xxx = 0, yyy = 0;
	//for (LL i = 1; i <= 1000000000; i++)
		//xxx += 1000000000 % i;
	//for (LL i = 1; i <= 999999999; i++)
		//yyy += 999999999 % i;
	//printf("%lld %lld\n", xxx, yyy);
	return 0;
}
