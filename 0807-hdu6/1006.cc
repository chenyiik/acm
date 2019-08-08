#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

int gcd(int a, int b) { return !b ? a : gcd(b, a % b); }
int lcm(int a, int b) { return a / gcd(a, b) * b; }

namespace cyc
{
	typedef long long LL;
	struct P { int x, y, k, t; } a[15];
	struct R { int k, b; } l[2][15];
	int X[15], Y[15];

	void main()
	{
		int n, m, xn = 0, yn = 0;
		scanf("%d%d", &n, &m);
		for (int i = 0; i < n; i++)
			scanf("%d%d", &a[i].x, &a[i].y), X[xn++] = a[i].x, Y[yn++] = a[i].y;
		sort(X, X + xn), xn = unique(X, X + xn) - X, sort(Y, Y + yn), yn = unique(Y, Y + yn) - Y;
		X[xn] = Y[yn] = m + 1;
		LL ans = 0;
		for (int ii = 0; ii < xn; ii++) for (int jj = 0; jj < yn; jj++)
		{
			int x0 = X[ii], x1 = X[ii + 1], y0 = Y[ii], y1 = Y[ii + 1], s[2] = {0, 0}, lm[2] = {1, 1}, ld[2] = {-1 -1};
			for (int i = 0; i < n; i++)
			{
				int p = 1, *ss = s + 1;
				if ((a[i].x <= x0 && a[i].y <= y0) || (a[i].x > x1 && a[i].y > y1)) p = 0, ss = s;
				l[p][*ss].k = a[i].k, l[p][(*ss)++].b = (a[i].y + (a[i].k - a[i].x % a[i].k)) % a[i].k;
			}
			for (int g = 0; g < 2; g++) if (s[g])
			{
				for (int i = 0; i < s[g]; i++) lm[g] = lcm(lm[g], l[g][i].k);
				for (int i = 0; i < lm[g]; i++)
				{
					bool bbb = true;
					for (int j = 0; j < s[g]; j++) if (l[g][j].b != i % lm[g]) bbb = false;
					if (bbb) { ld[g] = i; break; }
				}
			}
			if ((s[0] && ld[0] == -1) || (s[1] && ld[1] == -1)) continue;
			for (int g = 0; g < 2; g++) if (!s[g])
				for (int i = 0; i < lm[g]; i++)
				{
					int k = lm[g], b0 = ld[g], ts = (g ? -x0 : x0) + y0 - b0, x = x1 - x0, y = y1 - y0;
					long long i0 = ts / k + int(ts % k), b1 = b0 + k * i0 + (g ? x0 : -x0) - y0;
					ans += (x / k + int(x % k > i)) * (y / k + int(y % k > i));
					if (g == 0 && --b1 == -1) b1 = k - 1;
					if (g == 1 && ++b1 == k) b1 = 0;
				}
			if (!s[0] || !s[1]) continue;
			int x = x1 - x0, y = y1 - y0;
			int k0 = lm[0], bt = ld[0], ts = x0 + y0 - bt; 
			long long i0 = ts / k0 + int(ts % k0), b0 = bt + k0 * i0 - x0 - y0;
			int k1 = lm[1], bs = ld[1], tr = -x0 + y0 - bs; 
			long long i1 = tr / k1 + int(tr % k1), b1 = bs + k1 * i1 + x0 - y0;

		}
		printf("%lld\n", ans);
	}
}

int main()
{
	int t; scanf("%d", &t);
	while (t--) cyc::main();
	return 0;
}
