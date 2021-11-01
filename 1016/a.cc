#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

typedef long long LL;

const LL mod = int(1e9) + 7;

LL pow_mod(LL a, LL p, LL n = mod)
{
	if (p == 0)
		return 1;
	LL ans = pow_mod(a, p / 2, n);
	ans = ans * ans % n;
	if (p % 2 == 1)
		ans = ans * a % n;
	return ans;
}

int main()
{
	int _; scanf("%d", &_);
	while (_--)
	{
		int n; scanf("%d", &n);
		int l = 0, r = 0, t = 0, c = 0;
		for (int i = 0; i < n; i++)
		{
			int x; scanf("%d", &x);
			r = max(x, r);
			c++;
			if (c == r - l)
			{
				l = r;
				t++;
				c = 0;
			}
		}
//cout << t << endl;
		LL ans = pow_mod(2, t - 1);
		printf("%lld\n", ans);
	}
	return 0;
}
