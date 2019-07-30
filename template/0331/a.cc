#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int maxN = 100005;
struct P
{
	int pos, id, add;
	bool operator<(const P &o) const {
		return pos < o.pos || (pos == o.pos && add > o.add)
			|| (pos == o.pos && add == o.add && id < o.id);
	}
} a[maxN * 2];
int cnt[maxN * 2];
bool vis[maxN];
struct R { int low, high; } org[maxN];

int main()
{
	int n = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		R &e = org[i];
		scanf("%*d%d%*d%d", &e.high, &e.low);
		a[i * 2] = {e.low, i, 1};
		a[i * 2 + 1] = {e.high, i, -1};
	}
	sort(a, a + 2 * n);
	int maxP = 0;
	for (int i = 0; i < 2 * n; i++)
	{
		cnt[i] = cnt[i - 1] + a[i].add;
		if (cnt[i] > cnt[maxP])
			maxP = i;
	}
	int ans = cnt[maxP];
	for (int i = 0; i < n; i++)
	{
		R &e = org[i];
		if (e.low <= a[maxP].pos && e.high >= a[maxP].pos)
			vis[i] = true;
	}
	cnt[0] = vis[a[0].id] ? 0 : a[0].add;
	maxP = 0;
	for (int i = 0; i < 2 * n; i++)
	{
		cnt[i] = cnt[i - 1] + (vis[a[i].id] ? 0 : a[i].add);
		if (cnt[i] > cnt[maxP])
			maxP = i;
	}
	ans += cnt[maxP];
	printf("%d\n", ans);
	return 0;
}
