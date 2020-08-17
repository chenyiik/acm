#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <algorithm>

using namespace std;

const int maxN = 20005;

struct P
{
	int l, r;
	bool operator<(const P &o) const { return !(*this >= o); }
	bool operator>=(const P &o) const { return o <= *this; }
	bool operator<=(const P &o) const { return min(l, o.r) <= min(r, o.l); }
} a[maxN];

int main()
{
	srand(time(NULL));
	int t = 0;
	scanf("%d", &t);
	while (t--)
	{
		int n = 0;
		scanf("%d", &n);
		for (int i = 0; i < n; i++)
			scanf("%d%d", &a[i].l, &a[i].r);
		sort(a, a + n);
		long long pre = 0, ans = 0, le = 0;
		for (int i = 0; i < n; i++)
		{
			le += a[i].l;
			pre = max(pre, le) + a[i].r;
			ans = max(ans, pre);
		}
		printf("%lld\n", ans);
	}
	return 0;
}
