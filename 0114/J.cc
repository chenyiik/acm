#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int maxn = int(1e5) + 5;
int a[maxn];

int main()
{
	int n, m, s; scanf("%d%d%d", &n, &m, &s);
	for (int i = 0; i < m; i++)
		scanf("%d", &a[i]);
	if (s >= m)
	{
		printf("%d\n", n - m + 1);
		return 0;
	}
	sort(a, a + m);
	int M = unique(a, a + m) - a;
	int ans = 0, l = 0;
	for (int r = 0; r < M; r++)
	{
		while (a[r] - a[l] + 1 > m)
		{
			if (r - l + s >= m && a[l] + m - 1 <= n)
				ans += a[l + 1] - a[l];
			//cout << a[l] << ' ' << ans << endl;
			l++;
		}
	}

	printf("%d\n", ans);
	return 0;
}
