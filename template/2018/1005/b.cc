#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	const int maxN = static_cast<int>(1e5) + 7;
	static int a[maxN], c[maxN];
	static bool vis[maxN];
	memset(vis, 0, sizeof(vis));
	int n = 0, s = 0;
	scanf("%d%d", &n, &s);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	sort(a, a + n);

	int i = 0, j = n - 1, k = 0;
	while (i < j)
	{
		if (a[i] + a[j] <= s)
			i++;
		else
		{
			c[k++] = a[i];
			c[k++] = a[j];
			vis[i++] = true;
			vis[j--] = true;
		}
	}
	for (int i = n - 1; i >= 0; i--)
	{
		if (!vis[i])
			c[k++] = a[i];
	}

	int ans = 0;
	for (int i = 0; i < n; i++)
	{
		ans++;
		if (c[i] + c[i + 1] <= s)
			i++;
	}
	printf("%d\n", ans);
	for (int i = 0; i < n; i++)
		printf("%d ", c[i]);
	return 0;
}
