#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int maxn = int(1e5) + 10;
double a[maxn];

const double eps = 1e-9;

int main()
{
	int T; scanf("%d", &T);
	while (T--)
	{
		int n; double d; scanf("%d%lf", &n, &d);
		for (int i = 0; i < n; i++)
			scanf("%lf", &a[i]);
		if (a[n - 1] - a[n - 2] > a[1] - a[0])
		{
			for (int i = 0; i < n / 2; i++)
				swap(a[i], a[n - i - 1]);
		}
		double m = (a[0] + a[1]) / 2;
		double r = m + (a[1] - m) / 2;
		double t = m - r, mt = t;
		for (int i = 2; i < n; i++)
		{

		}
	}
	return 0;
}
