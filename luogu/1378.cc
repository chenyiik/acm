#include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>

using namespace std;

namespace cyc
{
	struct P 
	{ 
		int bh;
		double x, y, r, w; 
	} a[10];

	double x0, x1, y0, y1, dist[10][10];
	int n;

	double get_dist(const P &a, const P &b)
	{
		double dx = a.x - b.x, dy = a.y - b.y;
		return sqrt(dx * dx + dy * dy);
	}

	int solve()
	{
		scanf("%d%lf%lf%lf%lf", &n, &x0, &y0, &x1, &y1);
		for (int i = 0; i < n; i++)
		{
			a[i].bh = i;
			scanf("%lf%lf", &a[i].x, &a[i].y);
			for (int j = 0; j < i; j++)
				dist[i][j] = dist[j][i] = get_dist(a[i], a[j]);
			double lx = fabs(a[i].x - x0), rx = fabs(a[i].x - x1);
			double ly = fabs(a[i].y - y0), ry = fabs(a[i].y - y1);
			a[i].w = min(min(lx, rx), min(ly, ry));
		}
		double ans = 0.0;
		do
		{
			double area = 0.0;
			for (int i = 0; i < n; i++)
			{
				a[i].r = a[i].w;
				for (int j = 0; j < i; j++)
					a[i].r = min(a[i].r, dist[a[i].bh][a[j].bh] - a[j].r);
				a[i].r = max(a[i].r, 0.0);
				area += M_PI * a[i].r * a[i].r;
			}
			ans = max(ans, area);
		} while (next_permutation(a, a + n, [](const P &a, const P &b) { return a.bh < b.bh; }));
		double area = fabs((x1 - x0) * (y1 - y0));
		printf("%d\n", static_cast<int>(round(area - ans) + 1e-9));
		return 0;
	}
}

int main() { return cyc::solve(); }
