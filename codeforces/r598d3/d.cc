#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int maxn = int(1e6) + 5;
char a[maxn];

int main()
{
	int q; scanf("%d", &q);
	while (q--)
	{
		int n; long long k; scanf("%d%lld%s", &n, &k, a);
		int tot = 0;
		for (int i = 0; i < n && k; i++)
		{
			if (a[i] == '0')
			{
				if (i - tot <= k)
				{
					swap(a[i], a[tot]);
					k -= i - tot;
				}
				else
				{
					swap(a[i], a[i - k]);
					k = 0;
				}
				tot++;
			}
		}
		printf("%s\n", a);
	}
	return 0;
}
