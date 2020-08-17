#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n, m;
bool vis[30];

void out(int x, int y)
{
	int k = 0;
	for (int i = 1; x; i++, x >>= 1) if (x & 1)
		vis[i] = true, k++;
	printf("%d\n", k);
	for (int i = 1; i <= n; i++) if (vis[i])
		printf("%d ", i);
	puts("");
	memset(vis, 0, sizeof(vis)); k = 0;
	for (int i = 1; y; i++, y >>= 1) if (y & 1)
		vis[i] = true, k++;
	printf("%d\n", k);
	for (int i = 1; i <= n; i++) if (vis[i])
		printf("%d ", i);
	puts("");
	exit(0);
}

int f[(1 << 25) + 10];
int g[int(4e7) + 10];

void find(int x)
{
	int w = f[x], y = g[w];
	if (w == 0 || g[w] != 0)
	{
		int z = x & y;
		x &= ~(x & z);
		y &= ~(y & z);
		out(x, y);
	}
	g[w] = x;
}

int main()
{
	scanf("%d%d", &n, &m);
	int L = 1;
	for (int i = 1; i <= n; i++)
	{
		int x; scanf("%d", &x);
		for (int j = L; j < L * 2; j++)
			f[j] = (f[j - L] + x) % m, find(j);
		L *= 2;
	}
	puts("-1");
	return 0;
}
