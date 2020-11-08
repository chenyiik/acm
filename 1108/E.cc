#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int maxn = int(1e6) + 5;
int a[maxn];

int gcd(int a, int b) { return !b ? a : gcd(b, a % b); }

int main()
{
	int _; scanf("%d", &_);
	while (_--)
	{
		int n; scanf("%d", &n);
		for (int i = 0; i < n; i++)
			scanf("%d", &a[i]);
		int v = a[0];
		for (int i = 1; i < n; i++)
			v = gcd(v, a[i]);
		int m = 0;
		for (int i = 0; i < n; i++)
			if (a[i] == v)
				m++;
		m = max(m, 1);
		printf("%d\n", m / 2 + m % 2);
	}
	return 0;
}
