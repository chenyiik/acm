#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef long long LL;

const int maxn = int(5e4) + 5;
struct P { int p, a; bool b; } r[maxn];

bool cmp(P x, P y) { return x.p > y.p || x.p == y.p && x.a > y.a; }

int main()
{
	int _; scanf("%d", &_);
	while (_--)
	{
		int n; scanf("%d", &n);
		for (int i = 0; i < n; i++)
			scanf("%d%d", &r[i].p, &r[i].a), r[i].b = false;
		sort(r, r + n, cmp);
		vector<P> v;
		v.push_back(r[0]);
		for (int i = 1; i < n; i++)
		{
			P &last = v.back();
			if (last.a < r[i].a)
			{
				while (v.size() > 1)
				{
					P x = r[v.size() - 2], y = r[v.size() - 1], z = r[i];
					LL p = LL(x.p - y.p) * (z.a - x.a);
					LL q = LL(x.p - z.p) * (y.a - x.a);
					if (p >= q) v.pop_back();
					else break;
				}
				v.push_back(r[i]);
			}
			else if (last.p == r[i].p && last.a == r[i].a)
				last.b = true;
		}
		int ans = 0;
		for (P i : v) if (!i.b) ans++;
		printf("%d\n", ans);
	}
	return 0;
}
