#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	static char _s[1005], *s;
	static int a[1005], m, p[1005];
	static bool vis[1005];
	while (~scanf("%s%d", _s, &m))
	{
		s = _s;
		while (m && s[0])
		{
			char *t = s;
			while (t[0] && t[0] != '0')
				t++;
			if (!t[0])
				break;
			if (t - s <= m)
				m -= t - s;
			else
				break;
			s = t;
			do
				s++;
			while (s[0] == '0');
		}
		if (!s[0])
		{
			puts("0");
			continue;
		}
		int n = strlen(s);
		for (int i = 0; i < n; i++)
		{
			a[i] = s[i] - '0';
			p[i] = i;
		}
		sort(p, p + n, [](int x, int y) { return a[x] > a[y] || a[x] == a[y] && x < y; });
		memset(vis, true, sizeof(vis));
		for (int i = 0; i < m; i++)
			vis[p[i]] = false;
		bool b = false;
		for (int i = 0; i < n; i++)
		{
			if (!vis[i] || !b && a[i] == 0)
				continue;
			printf("%d", a[i]);
			b = true;
		}
		puts(b ? "" : "0");
	}
	return 0;
}
