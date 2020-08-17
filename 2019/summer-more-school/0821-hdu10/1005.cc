#include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

typedef long long LL;

const int maxn = int(1e5) + 7;
struct P { LL x, y; } a[maxn];
const LL oo = 0x7fffffffffffffffLL;

int main()
{
	int _; scanf("%d", &_);
	while (_--)
	{
		int n; scanf("%d", &n);
		multiset<LL> S;
		for (int i = 0; i < n; i++)
		{
			scanf("%lld%lld", &a[i].x, &a[i].y);
			S.insert(a[i].y);
		}
		sort(a, a + n, [](P a,P b){return a.x>b.x||(a.x==b.x&&a.y<a.y);});
		long long ans = +oo, pre = -oo;
		for (int i = 0; i < n; i++)
		{
			S.erase(S.find(a[i].y));
			ans = min(ans, abs(a[i].x - pre));
			if (a[i].x > pre && !S.empty() && *S.rbegin() > pre)
			{
				set<LL>::iterator t = S.upper_bound(a[i].x);
				if (t != S.end())
					ans = min(ans, abs(a[i].x - *t));
				if (t != S.begin())
					ans = min(ans, abs(a[i].x - *--t));
			}
			pre = max(pre, a[i].y);
		}
		printf("%lld\n", ans);
	}
	return 0;
}
