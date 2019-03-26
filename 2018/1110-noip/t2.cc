#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int t = 0;
	scanf("%d", &t);
	while (t--)
	{
		int n = 0;
		scanf("%d", &n);
		const int maxN = 105, maxM = 25007;
		static int a[maxN];
		for (int i = 0; i < n; i++)
			scanf("%d", &a[i]);
		sort(a, a + n);
		n = unique(a, a + n) - a;
		static bool b[maxM];
		memset(b, false, sizeof(b));
		b[0] = true;
		int ans = 0;
		for (int i = 0; i < n; i++)
		{
			if (!b[a[i]])
				ans++;
			for (int j = 0; j <= 25000 - a[i]; j++)
			{
				if (b[j])
					b[j + a[i]] = true;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
