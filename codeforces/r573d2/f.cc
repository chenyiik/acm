#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int maxn = int(2e5) + 5;
int C[maxn], n;
int lowbit(int x) { return x & -x; }
int sum(int x) { int ret = 0; while (x > 0) { ret += C[x]; x -= lowbit(x); } return ret; }
void add(int x, int d = 1) { while (x <= n) { C[x] += d; x += lowbit(x); } }
int gs(int l, int r) { return sum(r) - sum(l - 1); }
int gc(int i) { return gs(i, i); }

long long f(long long a) { return (1 + a) * a / 2; } 

struct P { int x, y; } a[maxn];

bool cmp(const P &a, const P &b) { return a.x < b.x || a.x == b.x && a.y < b.y; }
bool dmp(const P &a, const P &b) { return a.y > b.y || a.y == b.y && a.x < b.x; }

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d%d", &a[i].x, &a[i].y);
	sort(a, a + n, cmp);
	int mark = 1;
	for (int i = 0; i < n - 1; i++)
		a[i].x = a[i].x == a[i + 1].x ? mark : mark++;
	a[n - 1].x = mark;
	sort(a, a + n, dmp);
	long long ans = 0;
	for (int i = 0; i < n; )
	{
		int l = 1;
		do
		{
			ans -= f(gs(l, a[i].x - 1));
			if (gc(a[i].x) == 0)
				add(a[i].x);
			l = a[i].x + 1;
		} while (++i < n && a[i].y == a[i - 1].y);
		if (l <= n)
			ans -= f(gs(l, n));
		ans += f(sum(n));
	}
	printf("%lld\n", ans);
	return 0;
}
