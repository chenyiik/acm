#include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;

ll pow_mod(ll a, ll p, ll n)
{
	if (p == 0)
		return 1;
	ll ans = pow_mod(a, p / 2, n);
	ans = ans * ans % n;
	if (p % 2 == 1)
		ans = ans * a % n;
	return ans;
}

ll inv(ll a, ll n) { return pow_mod(a, n - 2, n); }
const double PI = acos(-1.0);

double f(const ll a[], ll n, double x)
{
	double fenmu = 1.0;
	for (int i = 0; i < n; i++)
		fenmu *= (a[i] * a[i] + x * x);
	return 1 / fenmu;
}

int main()
{
	const ll mod = int(1e9) + 7;
	ll n;
	static ll a[1005];
	while (~scanf("%lld", &n))
	{
		for (int i = 0; i < n; i++)
			scanf("%lld", &a[i]);
		double ans = 0.0;
		for (ll l = 0, r = 1, d = 10000000; r <= 1000000; l = l ? l * 10 : 1, r *= 10, d /= 10)
		{
			double tmp = 0.0;
			for (int i = l * d + 1; i <= r * d; i++)
				ans += f(a, n, i / (double)d) / d;
			ans += tmp;
		}
		/*
		const int t1 = 10000, t2 = 10000;
		for (int i = 1; i <= t1 * t2; i++)
			ans += f(a, n, i / (double)t2) / t2;
		*/
		cout << PI / ans << endl;
	}
	return 0;
}
