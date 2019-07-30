#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int maxN = static_cast<int>(1e5) + 9;
struct P { int w, b; } a[maxN];

typedef long long LL;

LL gcd(LL a, LL b) { return !b ? a : gcd(b, a % b); }

int main()
{
	int t = 0;
	scanf("%d", &t);
	while (t--)
	{
		int n = 0;
		LL W = 0, B = 0;
		scanf("%d", &n);
		for (int i = 0; i < n; i++)
		{
			int x;
			char s[3];
			scanf("%d%s", &x, s);
			if (*s == 'W')
				a[i] = {x, 0}, W += x;
			else
				a[i] = {0, x}, B += x;
		}
		if (W == 0)
		{
			printf("%lld\n", B);
			continue;
		}
		if (B == 0)
		{
			printf("%lld\n", W);
			continue;
		}
		LL g = gcd(W, B);
		W /= g, B /= g;
		//cout << W << ' ' << B << endl;

		LL WW = 0, BB = 0, ans = 0;
		for (int i = 0; i < n; i++)
		{
			//cout << WW << ' ' << BB << endl;
			if (a[i].w > 0)
			{
				if (BB == 0)
				{
					WW += a[i].w;
					continue;
				}
				LL k = W * BB / B - WW;
				if (k >= 0 && a[i].w >= k && W * BB == (WW + k) * B)
				{
					ans++;
					BB = 0;
					WW = a[i].w - k;
				}
				else
					WW += a[i].w;
			}
			else
			{
				if (WW == 0)
				{
					BB += a[i].b;
					continue;
				}
				LL k = B * WW / W - BB;
				if (k >= 0 && a[i].b >= k && B * WW == (BB + k) * W)
				{
					ans++;
					WW = 0;
					BB = a[i].b - k;
				}
				else
					BB += a[i].b;
			}
		}
		printf("%lld\n", ans);
	}
	return 0;
}
