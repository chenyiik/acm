#include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>

using namespace std;

const double esp = 1e-9, pi = acos(-1.0);
double get_dist(double x, double y) { return sqrt(x * x + y * y); }
double get_angle(double x, double y, double dist, double a)
{
	return acos(x / dist) * 180 / pi + a / 2;
}

int main()
{
	int n, X; scanf("%d%d", &n, &X);
	double a, T; int d; scanf("%lf%lf%d", &a, &T, &d);
	while (n--)
	{
		int x, y; scanf("%d%d", &x, &y);
		double dist = get_dist(x, y);
		if (dist > d + esp)
		{
			puts("0.00000000000");
			continue;
		}
		double angle = get_angle(x, y, dist, a);
		long long r = X / T + esp;
		double ti = r * (a / 360.0 * T), re = X - r * T;
		double low = re / T * 360, high = low + a;
		ti += angle > high - esp ? 0.0 : 
			(high - (angle > a - esp ? 0.0 : a - angle) 
			- max(angle, low)) / 360 * T;
		angle += 360;
		ti += angle > high - esp ? 0.0 : 
			(high - max(angle, low)) / 360 * T;
		printf("%.11f\n", ti);
	}
	return 0;
}
