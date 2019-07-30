#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

int a[70], n, tot2, nxt[70], nis[70];
bool vis[70];

bool dfs(int i, int s, int k, int len, int tot)
{
	//cout << i << ' ' << s << ' ' << k << ' ' << len << ' ' << tot << ' ' << tot2 << endl;
	if (k == 1)
		return true;
	if (i == n || s + tot < len)
		return false;
	if (vis[i])
		return dfs(nis[i], s, k, len, tot);
	if (s + a[i] > len)
		return dfs(nis[nxt[i]], s, k, len, tot - (nxt[i] - i) * a[i]);
	vis[i] = true;
	tot2 -= a[i];
	if (i == 0 || a[i] != a[i - 1])
		nis[i] = i + 1;
	else
		nis[nis[i]] = i + 1;
	//nis[nis[i]] = i + 1;
	if (s + a[i] == len && dfs(nis[0], 0, k - 1, len, tot2) || s + a[i] < len && dfs(i + 1, s + a[i], k, len, tot - a[i]))
		return true;
	if (i == 0 || a[i] != a[i - 1])
		nis[i] = i;
	else
		nis[nis[i]] = i;
	tot2 += a[i];
	vis[i] = false;
	if (s == 0 || s + a[i] == len)
		return false;
	if (dfs(nis[nxt[i]], s, k, len, tot - (nxt[i] - i) * a[i]))
		return true;
	return false;
}

int main()
{
	int m = 0, tot = 0;
	scanf("%d", &m);
	while (m--)
	{
		scanf("%d", &a[n]);
		if (a[n] <= 50)
			tot += a[n++];
	}
	tot2 = tot;
	sort(a, a + n, [](int x, int y) { return x > y; });
	nxt[n - 1] = n;
	for (int i = n - 2; i >= 0; i--)
		nxt[i] = a[i] == a[i + 1] ? nxt[i + 1] : i + 1;
	nis[0] = 0;
	for (int i = 1; i < n; i++)
		nis[i] = a[i] == a[i - 1] ? nis[i - 1] : i;
	for (int i = a[0]; i <= tot; i++)
		if (tot % i == 0 && tot / i <= n)
		{
			if (dfs(0, 0, tot / i, i, tot))
				return printf("%d\n", i), 0;
		}
}
