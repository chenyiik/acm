#include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>

using namespace std;

const int maxn = 15, K = 60;

struct P { int x, y, k, t; } node[maxn];
int a[maxn], b[maxn], an, bn;

bool cao(int x, int y, int n)
{
	for (int i = 0; i < n; i++)
	{
		const P &e = node[i];
		if ((abs(e.x - x) + abs(e.y - y)) % e.k != e.t)
			return false;
	}
	return true;
}

int main()
{
	int t; scanf("%d", &t);
	while (t--)
	{
		int n, m; scanf("%d%d", &n, &m);
		a[0] = b[0] = 0, a[1] = b[1] = m + 1, an = bn = 2;
		for (int i = 0; i < n; i++)
		{
			P &e = node[i];
			scanf("%d%d%d%d", &e.x, &e.y, &e.k, &e.t);
			a[an++] = e.x, b[bn++] = e.y;
		}
		sort(a, a + an), an = unique(a, a + an) - a;
		sort(b, b + bn), bn = unique(b, b + bn) - b;
		long long ans = 0;
		for (int i = 0; i < an; i++) for (int j = 0; j < bn; j++)
			for (int x = 0; x < K; x++) for (int y = 0; y < K; y++)
				if (cao(a[i] + x, b[j] + y, n))
				{
					long long u = a[i + 1] - a[i] - x - 1;
					long long v = b[j + 1] - b[j] - y - 1;
					u = u < 0 ? 0 : u / K + 1;
					v = v < 0 ? 0 : v / K + 1;
					ans += u * v;
				}
		printf("%lld\n", ans);
	}
	return 0;
}
