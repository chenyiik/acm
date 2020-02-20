#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int maxn = int(2e5) + 5;
int a[maxn];

int main()
{
	int n; scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	sort(a + 1, a + n + 1);
	double ans = 1.0;
	for (int i = 1; i <= n; i++)
	{
		if (a[i] <= i)
			ans = min(ans, double(a[i]) / i);
		else
			return puts("-1");
	}
	printf("%lf\n", ans);
	return 0;
}
