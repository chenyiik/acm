#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int maxn = 205;
int a[maxn], b[maxn];

int main()
{
	int T; scanf("%d", &T);
	while (T--)
	{
		int n, k; scanf("%d%d", &n, &k);
		for (int i = 0; i < n; i++)
			scanf("%d", &a[i]);
		for (int i = 0; i < n; i++)
			scanf("%d", &b[i]);
		a[0] += b[0];
		int d = 1;
		for (int i = 1; i < n; i++)
			if (a[i] > a[0])
				d++;
		if (d <= k)
			puts("Yes");
		else
			puts("No");
	}
	return 0;
}
