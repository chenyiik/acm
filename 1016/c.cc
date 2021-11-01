#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

typedef long long LL;

LL f(LL a, LL b, LL c, LL d, LL k)
{
	LL ans = 0;
//cout << a << ' ' << b << ' ' << c << ' ' << d << ' ' << k << ' ' << ans << endl;
	if ((c == 1 && d <= 1) || (c == 2 && d == 0))
	{
		if (k == 1)
			return 0;
		else
		{
			k--;
			c = 0;
		}
	}
//cout << a << ' ' << b << ' ' << c << ' ' << d << ' ' << k << ' ' << ans << endl;
	if (k == 1 && c > 0 && c < 3)
	{
		d -= 3 - c;
		c = 3;
	}
//cout << a << ' ' << b << ' ' << c << ' ' << d << ' ' << k << ' ' << ans << endl;
	ans += (b / 5) * 15, b = b % 5;
//cout << a << ' ' << b << ' ' << c << ' ' << d << ' ' << k << ' ' << ans << endl;
	if (b > 0 && d + b >= 5)
	{
		ans += 15;
		d -= 5 - b;
		b = 0;
	}
	ans += b;
	b = 0;
//cout << a << ' ' << b << ' ' << c << ' ' << d << ' ' << k << ' ' << ans << endl;
	if (c >= k * 3)
	{
		ans += 10 * k;
		c = 0;
	}
	else if (d + c >= k * 3)
	{
		ans += 10 * k;
		d -= k * 3 - c;
		c = 0;
	}
	else
	{
		if (c % 3 == 1 && d >= 2)
			c += 2, d -= 2;
		if (c % 3 == 2 && d >= 1)
			c += 1, d -= 1;
		ans += c / 3 * 10;
		c = 0;
		ans += d / 3 * 10;
		d %= 3;
	}
//cout << a << ' ' << b << ' ' << c << ' ' << d << ' ' << k << ' ' << ans << endl;
	ans += (a + d) * 3, a = d = 0;
//cout << a << ' ' << b << ' ' << c << ' ' << d << ' ' << k << ' ' << ans << endl;
	return ans;
}
		
int main()
{
	int _; scanf("%d", &_);
	while (_--)
	{
		LL a, b, c, d, k; scanf("%lld%lld%lld%lld%lld", &a, &b, &c, &d, &k);
		printf("%lld\n", f(a, b, c, d, k));
	}
	return 0;
}
