#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

const int rot = 1000;
int a[105], dp[1000];
set<int> S;

bool f(int i, int t)
{
	for (int j = i; j > i - t; j--)
	{
		if (dp[j % rot] != dp[(j - 1) % rot])
			return false;
	}
	return true;
}

int main()
{
	int l = 0, s = 0, t = 0, m = 0;
	scanf("%d%d%d%d", &l, &s, &t, &m);
	for (int i = 0; i < m; i++)
	{
		scanf("%d", &a[i]);
		S.insert(a[i]);
	}
	sort(a, a + m);
	if (s == t)
	{
		int ans = 0;
		for (int i = 0; i < m; i++)
			ans += (a[i] % s == 0);
		return printf("%d\n", ans), 0;
	}
	else
	{
		memset(dp, 0x3f, sizeof(dp));
		dp[0] = 0;
		int p = 0, cnt = 0;
		for (int i = 0; i < l; i++)
		{
			dp[(i + t) % rot] = 0x3f3f3f3f;
			for (int j = i + s; j <= i + t; j++)
				dp[j % rot] = min(dp[j % rot], dp[i % rot] + (S.find(j) != S.end()));
			if (S.find(i) != S.end())
			{
				cnt = 0;
				p++;
			}
			else if (++cnt > 200 && f(i, t))
			{
				int nxt = p == m ? l - t : a[p] - t, cp = dp[i % rot];
				for (int j = nxt; j < (p == m ? l : a[p]); j++)
					dp[j % rot] = cp;
				i = nxt - 1;
				cnt = 0;
			}
		}
		int ans = 0x3f3f3f3f;
		for (int i = l; i < l + t; i++)
			ans = min(ans, dp[i % rot]);
		return printf("%d\n", ans), 0;
	}
}
