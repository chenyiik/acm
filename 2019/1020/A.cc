#include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

const int maxn = 3005;
struct P { int x, y, r; } a[maxn];
/*struct P { double x, y, r; } a[maxn];

const double e = 1e-9;
bool lt(double a, double b) { return a < b; }
bool eq(double a, double b) { return a - b < e && b - a < e; }
bool le(double a, double b) { return lt(a, b) || eq(a, b); }

double dist(P a, P b)
{
	double dx = a.x - b.x, dy = a.y - b.y;
	return sqrt(dx * dx + dy * dy);
}
*/
bool d[maxn][maxn], vis[maxn];

int main()
{
	int N, M, n;
	scanf("%d%d%d", &M, &N, &n);
	int S = 0, T = n + 1;
	for (int i = 1; i <= n; i++)
	{
		//scanf("%lf%lf%lf", &a[i].x, &a[i].y, &a[i].r);
		scanf("%d%d%d", &a[i].x, &a[i].y, &a[i].r);
		//if (le(a[i].x, a[i].r) || le(N - a[i].y, a[i].r))
		if (a[i].x <= a[i].r || N - a[i].y <= a[i].r)
			d[S][i] = d[i][S] = true;
		//if (le(a[i].y, a[i].r) || le(M - a[i].x, a[i].r))
		if (a[i].y <= a[i].r || M - a[i].x <= a[i].r)
			d[T][i] = d[i][T] = true;
	}
	for (int i = 1; i <= n; i++)
		for (int j = i + 1; j <= n; j++)
		{
			int dx = a[i].x - a[j].x, dy = a[i].y - a[j].y,
				dk = a[i].r + a[j].r;
			//if (le(dist(a[i], a[j]), a[i].r + a[j].r))
			if (dx * dx + dy * dy <= dk * dk)
				d[i][j] = d[j][i] = true;
		}
	queue<int> Q;
	Q.push(S);
	while (!Q.empty())
	{
		int p = Q.front(); Q.pop();
		if (d[p][T])
			return puts("N"), 0;
		for (int i = 1; i <= n; i++) 
			if (!vis[i] && d[p][i])
				Q.push(i), vis[i] = true;
	}
	return puts("S"), 0;
}
