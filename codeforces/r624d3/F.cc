#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <stack>

using namespace std;

typedef long long LL;

const int maxn = int(2e5) + 5;
struct P { LL x, v, id; } a[maxn];

bool cmp(P a, P b) { return a.x < b.x; }
bool cmq(P a, P b) { return a.v == b.v ? a.x > b.x : a.v > b.v; }

LL C[maxn], D[maxn], n; //from 1 to n

LL lowbit(LL x) { return x & -x; }
LL sum(LL x);
LL sun(LL x);
void add(LL x, LL d);
void ade(LL x, LL d);

int main()
{
	scanf("%lld", &n);
	for (int i = 1; i <= n; i++) scanf("%lld", &a[i].x);
	for (int i = 1; i <= n; i++) scanf("%lld", &a[i].v);
	sort(a + 1, a + n + 1, cmp);
	for (int i = 1; i <= n; i++) a[i].id = i;
	sort(a + 1, a + n + 1, cmq);
	LL ans = 0;
	for (int i = 1; i <= n; i++)
	{
		LL cnt = sum(n) - sum(a[i].id);
		LL tot = sun(n) - sun(a[i].id);
		ans += tot - cnt * a[i].x;
		add(a[i].id, 1);
		ade(a[i].id, a[i].x);
	}
	printf("%lld\n", ans);
	return 0;
}

LL sum(LL x)
{
	LL ret = 0;
	while (x > 0)
	{
		ret += C[x];
		x -= lowbit(x);
	}
	return ret;
}
void add(LL x, LL d)
{
	while (x <= n)
	{
		C[x] += d;
		x += lowbit(x);
	}
}
LL sun(LL x)
{
	LL ret = 0;
	while (x > 0)
	{
		ret += D[x];
		x -= lowbit(x);
	}
	return ret;
}
void ade(LL x, LL d)
{
	while (x <= n)
	{
		D[x] += d;
		x += lowbit(x);
	}
}
