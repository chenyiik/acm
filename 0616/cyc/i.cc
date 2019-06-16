#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int t;
	scanf("%d", &t);
	while (t--)
	{
		int n, k, ans = 0;
		scanf("%d%d", &n, &k);
		static int a[10005];
		for (int i = 0; i < n; i++)
		{
			scanf("%d", &a[i]);
			ans += a[i];
		}
		sort(a, a + n);
		for (int i = 0; k > 0 && i < n && a[i] < 0; i++)
		{
			a[i] = -a[i];
			ans += a[i] * 2;
			k--;
		}
		sort(a, a + n);
		while (k--)
		{
			a[0] = -a[0];
			ans += a[0] * 2;
		}
		printf("%d\n", ans);
	}
	return 0;
}
