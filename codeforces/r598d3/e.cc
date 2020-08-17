#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int maxn = int(2e5) + 10;
struct P { int id, value, ans; } a[maxn];
int d[maxn], f[maxn], g[maxn];

int main()
{
	int n, tot = 0; scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%d", &a[i].value), a[i].id = i;
	sort(a, a + n, [](P a, P b) { return a.value < b.value; });
	for (int i = 1; i < n; i++) tot += d[i] = a[i].value - a[i - 1].value;
	int l = 0;
	for (int i = 3; i < n - 2; i++)
	{
		int x = i - 3;
		for (int j = i - 4; j > max(0, i - 6); j--)
			if (f[j] > f[x])
				x = j;
		f[i] = f[x] + d[i], g[i] = x;
		if (f[i] > f[l])
			l = i;
	}
	printf("%d ", tot - f[l]);
	int team = 0, r = n;
	while (true)
	{
		team++;
		for (int i = l; i < r; i++)
			a[i].ans = team;
		if (!l) break;
		r = l, l = g[l];
		if (l < 3)
			l = 0;
	}
	printf("%d\n", team);
	sort(a, a + n, [](P a, P b) { return a.id < b.id; });
	for (int i = 0; i < n; i++)
		printf("%d%c", a[i].ans, " \n"[i +  1 == n]);
	return 0;
}
