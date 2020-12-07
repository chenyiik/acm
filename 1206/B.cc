#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

const int maxn = int(1e6) + 10;
int a[maxn], f[maxn];

int main()
{
	int T; scanf("%d", &T);
	while (T--)
	{
		memset(f, 0, sizeof(f));
		int n; scanf("%d", &n);
		for (int i = 0; i < n; i++)
		{
			scanf("%d", &a[i]);
			f[a[i]]++;
		}
		for (int j = 0; j < 20; j++)
			for (int i = 1; i <= int(1e6); i++)
				if (i & (1 << j))
					f[i] += f[i ^ (1 << j)];
		long long ans = 0;
		for (int i = 0; i < n; i++)
			ans += f[a[i]];
		printf("%lld\n", ans);
	}
	return 0;
}
