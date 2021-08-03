#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int oo = 0x7fffffff;

int a[20], n;

int f()
{
	for (int i = 0; i < int(1e6); i++)
	{
		sort(a, a + n);
		int max_num = a[n - 1], min_num = a[0], d = max_num - min_num;
		if (d == 0)
			return max_num;
		a[0] = a[n - 1] = d;
	}
	return +oo;
}

int main()
{
	int t; scanf("%d", &t);
	while (t--)
	{
		scanf("%d", &n);
		for (int i = 0; i < n; i++)
			scanf("%d", &a[i]);
		int ans = f();
		if (ans == +oo)
			puts("Impossible");
		else
			printf("%d\n", ans);
	}
	return 0;
}
