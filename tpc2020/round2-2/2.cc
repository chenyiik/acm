#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int maxn = 15;
struct P { int c, v, x, y; } a[maxn];
int p[maxn];

bool cmp0(int l, int r) { return a[l].y > a[r].y || (a[l].y == a[r].y && a[l].x < a[r].x); }
bool cmp1(int l, int r) { return a[l].v > a[r].v || (a[l].v == a[r].v && a[l].c < a[r].c); }

int main()
{
	int _; scanf("%d", &_);
	while (_--)
	{
		int n, m; scanf("%d%d", &n, &m);
		for (int i = 0; i < n; i++)
		{
			P &e = a[i];
			scanf("%d%d%d%d", &e.c, &e.v, &e.x, &e.y);
			e.x += e.c, e.y += e.v;
			p[i] = i;
		}
		sort(p, p + n, cmp1);
		int ans1 = 0, ans2 = 0;
		for (int sp = 0; sp < n; sp++)
		{
			int tot1 = a[sp].y, tot2 = a[sp].x, mm = m - 1;
			for (int i = 0; mm--; i++)
			{
				if (p[i] == sp) { mm++; }
				else tot1 += a[p[i]].v, tot2 += a[p[i]].c;
			}
			if (tot1 > ans1 || (tot1 == ans1 && tot2 < ans2))
				ans1 = tot1, ans2 = tot2;
		}
		printf("%d %d\n", ans1, ans2);
	}
	return 0;
}

bool cmp2(int l, int r)
{ 
	if (a[l].v + a[l].y == a[r].v + a[r].y) return a[l].c + a[l].x < a[r].c + a[r].x;
	else return a[l].v + a[l].y > a[r].v + a[r].y; 
}
bool cmp3(int l, int r) 
{ 
	if (a[l].v == a[r].v) return a[l].c < a[r].c;
	else return a[l].v > a[r].v;
}
