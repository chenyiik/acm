#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int maxn = int(1e5) + 5;
double a[maxn];

int main()
{
	int t; scanf("%d", &t);
	while (t--)
	{
		int n, k; scanf("%d%d", &n, &k);
		double tot = 0;
		for (int i = 0; i < n; i++)
			scanf("%lf", &a[i]), tot += a[i];
		for (int i = 0; i < n; i++)
			printf("%.8f%c", a[i] + a[i] * k / tot, " \n"[i + 1 == n]);
	}
	return 0;
}
