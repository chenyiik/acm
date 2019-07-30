#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

typedef int LL;

const int maxN = 500007, maxL = 1000007;
LL a[maxN], c[maxN], pos[maxL], n;

long lowbit(LL x) { return x & -x; }

LL sum(LL x)
{
	LL ret = 0;
	while (x > 0)
	{
		ret += c[x];
		x -= lowbit(x);
	}
	return ret;
}

void add(LL x, LL d)
{
	while (x <= n)
	{
		c[x] += d;
		x += lowbit(x);
	}
}

struct P { int ans, pos, lef, rig; } q[maxN];

auto cmp = [](P a, P b) { return a.rig < b.rig || a.rig == b.rig && a.pos < b.pos; };
auto cmq = [](P a, P b) { return a.pos < b.pos; };

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	int m = 0;
	scanf("%d", &m);
	for (int i = 0; i < m; i++)
	{
		q[i].pos = i;
		scanf("%d%d", &q[i].lef, &q[i].rig);
	}
	sort(q, q + m, cmp);
	for (int i = 1, p = 0; i <= n; i++)
	{
		if (pos[a[i]] != 0)
			add(pos[a[i]], -1);
		add(pos[a[i]] = i, 1);
		while (p < m && q[p].rig == i)
		{
			q[p].ans = sum(q[p].rig) - sum(q[p].lef - 1);
			p++;
		}
	}
	sort(q, q + m, cmq);
	for (int i = 0; i < m; i++)
		printf("%d\n", q[i].ans);
	return 0;
}
