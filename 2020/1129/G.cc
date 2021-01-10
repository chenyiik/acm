#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int maxn = int(1e6) + 5;
int c[maxn];

int main()
{
	for (int n; ~scanf("%d", &n); )
	{
		for (int i = 1; i <= n; i++) c[i] = 0;
		for (int i = 1; i <= n; i++)
		{
			int x; scanf("%d", &x);
			c[x]++;
		}
		long long ans = 0;
		for (int i = 1; i <= n; i++)
		{
			if (i >= 3 && c[i] > 0 && c[i - 1] > 0 && c[i - 2] > 0)
			{
				ans++;
				c[i - 2]--, c[i - 1]--, c[i]--;
			}
			ans += c[i] / 2;
			c[i] %= 2;
		}
		printf("%lld\n", ans);
	}
	return 0;
}
