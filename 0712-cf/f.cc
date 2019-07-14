#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int maxn = int(2e5) + 5;
int C[maxn], n;

int lowbit(int x) { return x & -x; }

int sum(int x)
{
	int ret = 0;
	while (x > 0)
	{
		ret += C[x];
		x -= lowbit(x);
	}
	return ret;
}

void add(int x, int d = 1)
{
	while (x <= n)
	{
		C[x] += d;
		x += lowbit(x);
	}
}

struct P { int x, y; } a[maxn];

bool cmp0(const P &a, const P &b) { return a.y < b.y || (a.y == b.y && a.x < b.x); }
bool cmp1(const P &a, const P &b) { return a.x < b.x || (a.x == b.x && a.y < b.y); }

int mmp[maxn], m;

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d%d", &a[i].x, &a[i].y);
	sort(a, a + n, cmp0);
	mmp[0] = m = 1;
	for (int i = 1; i < n; i++)
	{
		if (a[i].y != a[i - 1].y)
			m++;
		mmp[i] = m;
	}
	for (int i = 0; i < n; i++)
		a[i].y = mmp[i];
	sort(a, a + n, cmp1);
	long long ans = 0;
	add(a[0].y);
	for (int i = 1; i < n; i++)
	{
		if (a[i].x != a[i - 1].x)
			ans += sum(a[i - 1].y);
		add(a[i].y);
	}
	ans += sum(a[n - 1].y);
	printf("%lld", ans);
	return 0;
}
