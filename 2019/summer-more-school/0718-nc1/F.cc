#include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;

//double f(ll x1, ll y1, ll x2, ll y2, ll x3, ll y3) { return abs(x1*y2+x2*y3+x3*y1-x1*y3-x2*y1-x3*y2) / 2.0; }
ll f(ll x1, ll y1, ll x2, ll y2, ll x3, ll y3) { return abs(x1*y2+x2*y3+x3*y1-x1*y3-x2*y1-x3*y2); }

int main()
{
	ll x1, y1, x2, y2, x3, y3;
	while (~scanf("%lld%lld%lld%lld%lld%lld", &x1, &y1, &x2, &y2, &x3, &y3))
	{
		ll a = f(x1, y1, x2, y2, x3, y3);
		printf("%lld\n", a * 11);
	}
	/*
	long long maxX = int(1e4), maxY = int(1e4);
	long long T = f(0, 0, maxX, 0, 0, maxY);
	ll x1 = 0, y1 = 0, x2 = maxX, y2 = 0, x3 = 0, y3 = maxY;
	double S = 0.0;
	ll tot = 0;
	for (int i = 0; i <= maxY; i++)
		for (int j = 0; j <= maxX - i; j++)
		{
			double A = f(x1, y1, x2, y2, j, i);
			double B = f(x1, y1, x3, y3, j, i);
			double C = f(x3, y3, x2, y2, j, i);
			S += max(max(A, B), C);
			tot++;
		}
	cout << S / tot / T << endl;
	*/
	return 0;
}

