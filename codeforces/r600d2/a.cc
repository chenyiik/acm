#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int maxn = int(1e5) + 5;
int a[maxn];

void solve()
{
	int n; scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	for (int i = 0; i < n; i++)
	{
		int x; scanf("%d", &x);
		a[i] = x - a[i];
	}
	int l = 0, r = n - 1;
	while (l < n && a[l] == 0)
		l++;
	while (r > l && a[r] == 0)
		r--;
	for (int i = l; i <= r; i++)
	{
		if (a[i] < 0 || a[i] != a[l])
		{
			puts("NO");
			return;
		}
	}
	puts("YES");
}

int main()
{
	int t; scanf("%d", &t);
	while (t--)
		solve();
	return 0;
}
