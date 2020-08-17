#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int t;
	scanf("%d", &t);
	while (t--)
	{
		int n, m;
		scanf("%d%d", &n, &m);
		static int a[1005][1005];
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
				scanf("%d", &a[i][j]);
			sort(a[i], a[i] + m);
		}
		int ans = 0;
		for (int i = 0; i + 1 < n; i++)
		{
			int *b = a[i], *c = a[i + 1];
			int bi = 0, ci = 0;
			while (bi < m && ci < m)
			{
				if (b[bi] == c[ci])
					ans++, bi++, ci++;
				else if (b[bi] < c[ci])
					bi++;
				else if (b[bi] > c[ci])
					ci++;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
