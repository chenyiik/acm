#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

int lowbit(int x) { return x & -x; }

const int maxn = int(2e5) + 5;
int a[maxn];

int f(int x)
{
	int bit = 0;
	while (x & 1)
		bit++, x >>= 1;
	return 1 << bit;
}

int main()
{
	int t;
	scanf("%d", &t);
	while (t--)
	{
		int n;
		scanf("%d", &n);
		long long ans = 0;
		for (int i = 2; i <= n; i++)
		{
			int x = f(i);
			if (x > n)
				a[i] = 1, ans += 1 & i;
			else
				a[i] = x, ans += x & i;
		}
		printf("%lld\n", ans);
		for (int i = 2; i <= n; i++)
			printf("%d%c", a[i], " \n"[i == n]);
	}
	return 0;
}
