#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <utility>

using namespace std;

const int maxn = 300000 + 7;
pair<int, int> a[maxn];
int vis[maxn];

int main()
{
	int n;
	scanf("%d", &n);
	n = n / 2;
	for (int i = 0; i < n; i++)
	{
		scanf("%d%d", &a[i].first, &a[i].second);
		if (a[i].first > a[i].second)
			swap(a[i].first, a[i].second);
	}
	sort(a, a + n);
	memset(vis, 0, sizeof(vis));
	int val = 0;
	for (int i = 0; i < n; i++)
	{
		if (a[i].first >= val)
		{
			vis[i] = 1;
			val = a[i].second;
		}
	}
	val = 0;
	for (int i = 0; i < n; i++)
	{
		if (vis[i] == 0 && a[i].first >= val)
		{
			vis[i] = 2;
			val = a[i].second;
		}
	}
	for (int i = 0; i < n; i++)
	{
		if (vis[i] == 0)
			return puts("-1"), 0;
	}
	int cnt = 0;
	for (int i = 0; i < n; i++)
	{
		if (vis[i] == 1)
			printf("%d %d%c", a[i].first, a[i].second, " \n"[++cnt == n]);
	}
	for (int i = n - 1; i >= 0; i--)
	{
		if (vis[i] == 2)
			printf("%d %d%c", a[i].second, a[i].first, " \n"[++cnt == n]);
	}
	return 0;
}
