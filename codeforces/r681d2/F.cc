#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int maxn = int(2e5) + 5, mod = 998244353;
int a[maxn], p[maxn];
bool b[maxn];

int main()
{
	int t; scanf("%d", &t);
	while (t--)
	{
		int n, k; scanf("%d%d", &n, &k);
		for (int i = 1; i <= n; i++)
			b[i] = true;
		b[n + 1] = false;
		for (int i = 1; i <= n; i++)
		{
			int x; scanf("%d", &x);
			a[x] = i;
		}
		for (int i = 0; i < k; i++)
		{
			int x; scanf("%d", &x);
			p[i] = a[x];
			b[p[i]] = false;
		}
		int ans = 1;
		for (int i = 0; i < k; i++)
		{
			if (!b[p[i] - 1] && !b[p[i] + 1])
			{
				ans = 0;
				break;
			}
			if (b[p[i] - 1] && b[p[i] + 1])
				ans = ans * 2 % mod;
			b[p[i]] = true;
		}
		printf("%d\n", ans);
	}
	return 0;
}
