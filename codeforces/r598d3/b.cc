#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int maxn = 105;
int a[maxn];
bool vis[maxn];

int main()
{
	int q; scanf("%d", &q);
	while (q--)
	{
		int n; scanf("%d", &n);
		for (int i = 1; i <= n; i++)
			scanf("%d", &a[i]);
		int st = 1, mi = 1;
		memset(vis, 0, sizeof(vis));
		for (int i = 1; i <= n; i++)
		{
			vis[a[i]] = true;
			if (mi == a[i])
			{
				for (int j = i; j > st; j--)
				{
					if (a[j] > a[j - 1])
						break;
					swap(a[j], a[j - 1]);
				}
				st = i;
				for (int j = 1; j <= n; j++) if (!vis[j])
					mi = j, j = n;
			}
		}
		for (int i = 1; i <= n; i++)
			printf("%d%c", a[i], " \n"[i == n]);
	}
	return 0;
}
