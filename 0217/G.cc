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
	double hudu = acos(x / dist);
	if (y < 0)
		hudu = 2.0 * pi - hudu;
	double angle = hudu * 360 / (2.0 * pi);
	angle = angle + a / 2 + esp;
	if (angle > 360)
		angle -= 360;
	return angle;
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
		double ti = int(X / T + esp) * (a / 360.0 * T);
		double re = X - int(X / T + esp) * T;
		double low = re / T * 360;
		double high = low + a;
		double me = angle > high - esp ? 0.0 : 
			(high - (angle > a - esp ? 0.0 : a - angle) 
			- max(angle, low)) / 360 * T;
		printf("%.11f\n", ti + me);

	}
	return 0;
}
