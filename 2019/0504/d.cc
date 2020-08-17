#include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>

using namespace std;

int gcd(int a, int b) { return !b ? a : gcd(b, a % b); }

const double esp = 1e-9;
bool equ(double a, double b) { return a - esp < b && a + esp > b; } 


const int maxN = 1005;
struct P { double x, y, r; } a[maxN];

double dist(P a, P b)
{
	double x = a.x - b.x, y = a.y - b.y;
	return sqrt(x * x + y * y);
}

bool G[maxN][maxN];

struct R
{
	int stat;
	int p, q;
} f[maxN];

int n = 0;
bool vis[maxN];

void dfs(int u)
{
	vis[u] = true;
	for (int i = 0; i < n; i++)
	{
		if (vis[i] || !G[u][i])
			continue;
		f[i].stat = f[u].stat ^ 1 ^ 2;
		f[i].p = a[u].r * f[u].p;
		f[i].q = a[i].r * f[u].q;
		int g = gcd(f[i].p, f[i].q);
		f[i].p /= g;
		f[i].q /= g;
		dfs(i);
	}
}

int main()
{
	int t = 0;
	scanf("%d", &t);
	while (t--)
	{
		scanf("%d", &n);
		for (int i = 0; i < n; i++)
			scanf("%lf%lf%lf", &a[i].x, &a[i].y, &a[i].r);
		for (int i = 0; i < n - 1; i++)
			for (int j = i + 1; j < n; j++)
				G[i][j] = G[j][i] = equ(dist(a[i], a[j]), a[i].r + a[j].r);
		memset(f, 0, sizeof(f));
		memset(vis, 0, sizeof(vis));
		f[0] = {1, 1, 1};
		dfs(0);
		const char *st0 = "not moving";
		const char *st1 = " clockwise";
		const char *st2 = " counterclockwise";
		for (int i = 0; i < n; i++)
		{
			if (f[i].stat == 0)
				puts(st0);
			else
			{
				printf("%d", f[i].p);
				if (f[i].q != 1)
					printf("/%d", f[i].q);
				puts(f[i].stat == 1 ? st1 : st2);
			}
		}
	}
	return 0;
}
