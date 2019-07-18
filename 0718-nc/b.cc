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
		for (int i = 1; i < 10000 * 10000; i++)
			ans += f(a, n, i / 10000.0);
		cout << PI / ans * 10000 << endl;
	}
	return 0;
}
