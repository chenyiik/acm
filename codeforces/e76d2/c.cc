#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int maxn = int(2e5) + 5;
int a[maxn];

int main()
{
	int t; scanf("%d", &t);
	while (t--)
	{
		int n; scanf("%d", &n);
		memset(a + 1, -1, sizeof(int) * n);
		unsigned ans = -1;
		for (int i = 0; i < n; i++)
		{
			int x; scanf("%d", &x);
			if (a[x] > -1)
				ans = min(ans, unsigned(i - a[x] + 1));
			a[x] = i;
		}
		printf("%d\n", ans);
	}
	return 0;
}
