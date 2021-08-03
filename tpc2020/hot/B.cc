#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int maxn = int(1e4) + 5;
int a[maxn];

int main()
{
	int t; scanf("%d", &t);
	while (t--)
	{
		int n, m; scanf("%d%d", &n, &m);
		for (int i = 0; i < n; i++)
			scanf("%d", &a[i]);
		sort(a, a + n);
		long long sum = 0;
		for (int i = 0; i < m; i++)
		{
			int j = 2 * m - i - 1;
			sum += a[i] * a[j];
		}
		printf("%lld\n", sum);
	}
	return 0;
}
