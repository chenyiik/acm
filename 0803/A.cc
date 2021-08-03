#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int maxn = 105;
int a[maxn];

void solve(int n, int k)
{
	int u = 0, v = 0;
	for (int i = 0; i < 2 * n; i++)
	{
		if (a[i % n] == u)
			v++;
		else
			u = a[i % n], v = 1;
		if (v == k)
		{
			printf("%d %d\n", i + 1, u);
			return;
		}
	}
	if (v == 2 * n)
		printf("%d %d\n", k, u);
	else
		puts("INF");
}

int main()
{
	int _; scanf("%d", &_);
	while (_--)
	{
		int n, k; scanf("%d%d", &n, &k);
		for (int i = 0; i < n; i++)
			scanf("%d", &a[i]);
		solve(n, k);
	}
	return 0;
}
