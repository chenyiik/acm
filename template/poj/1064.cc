#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int maxN = static_cast<int>(1e4) + 7;
int a[maxN], n, k;

int check(int d)
{
	int ans = 0;
	for (int i = 0; i < n; i++)
		ans += a[i] / d;
	return ans;
}

int main()
{
	scanf("%d%d", &n, &k);
	for (int i = 0; i < n; i++)
	{
		double d = 0.0;
		scanf("%lf", &d);
		a[i] = static_cast<int>(d * 100 + 1e-9);
	}
	int l = 0, r = static_cast<int>(1e7) + 1;
	while (l + 1 < r)
	{
		int mid = (l + r) / 2;
		if (check(mid) >= k)
			l = mid;
		else
			r = mid;
	}
	printf("%.2f\n", l / 100.00);
	return 0;
}
