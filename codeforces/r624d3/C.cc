#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int maxn = int(2e5) + 5;
char s[maxn];
int p[maxn];
long long ans[255];

int main()
{
	int t; scanf("%d", &t);
	while (t--)
	{
		memset(ans, 0, sizeof(ans));
		int n, m; scanf("%d%d%s", &n, &m, s + 1);
		for (int i = 0; i < m; i++)
			scanf("%d", &p[i]);
		sort(p, p + m);
		int cnt = m + 1, r = 0;
		for (int i = 1; i <= n; i++)
		{
			ans[s[i]] += cnt;
			while (r < m && p[r] == i)
				r++, cnt--;
		}
		for (char c = 'a'; c <= 'z'; c++)
			printf("%lld%c", ans[c], " \n"[c == 'z']);
	}
	return 0;
}
