#include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>

using namespace std;

const int maxn = 4005;
struct P { long long x, y, g; int e; } c[maxn], d[maxn];

int fe(int x, int y)
{
	if (x > 0 && y >= 0) return 0;
	else if (x <= 0 && y > 0) return 1;
	else if (x < 0 && y <= 0) return 2;
	else if (x >= 0 && y < 0) return 3;
}

bool cmq(const P &a, const P &b) { return a.y * b.x < b.y * a.x; }
bool cmp(const P &a, const P &b) { return a.e == b.e ? cmq(a, b) : a.e < b.e; }

bool fp(const P &a, const P &b)
{
	int ee = (b.e - a.e + 4) % 4;
	if (ee == 0) return cmq(a, b);
	if (ee == 1) return true;
	if (ee == 2) return cmq(a, b);
	if (ee == 3) return false;
}

int main()
{
	int n; scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%lld%lld%lld", &c[i].x, &c[i].y, &c[i].g);
	long long ans = 0x7fffffffffffffff;
	for (int node = 0; node < n; node++)
	{
		for (int i = 0, j = 0; i < n; i++)
		{
			if (i == node) continue;
			d[j].x = c[i].x - c[node].x, d[j].y = c[i].y - c[node].y;
			d[j].g = c[i].g, d[j].e = fe(d[j].x, d[j].y);
			j++;
		}
		sort(d, d + n - 1, cmp);
		long long tota = 0, totb = 0;
		int p = 1;
		while (p < n - 1 && fp(d[0], d[p])) tota += d[p].g, p++;
		for (int i = p; i < n - 1; i++) totb += d[i].g;
		ans = min(ans, abs(tota - totb));
		if (p == n - 1) p = 0;
		for (int i = 1; i < n - 1; i++)
		{
			tota -= d[i].g, totb += d[i - 1].g;
			while (p != i && fp(d[i], d[p]))
			{
				tota += d[p].g, totb -= d[p].g;
				if (++p == n - 1) p = 0;
			}
			ans = min(ans, abs(tota - totb));
		}
	}
	printf("%lld\n", ans);
	return 0;
}
