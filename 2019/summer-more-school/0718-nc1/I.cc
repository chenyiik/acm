#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef long long LL;

const int K = 4;
const int maxn = (100000 + 10) * K;
LL minv[maxn], maxv[maxn], sumv[maxn], addv[maxn];

void maintain(int o, int L, int R)
{
	int lc = o * 2, rc = o * 2 + 1;
	sumv[o] = minv[o] = maxv[o] = 0;
	if (R > L)
	{
		sumv[o] = sumv[lc] + sumv[rc];
		minv[o] = min(minv[lc], minv[rc]);
		maxv[o] = max(maxv[lc], maxv[rc]);
	}
	minv[o] += addv[o];
	maxv[o] += addv[o];
	sumv[o] += addv[o] * (R - L + 1);
}

int ql, qr; LL v;

void update(int o, int L, int R) //let [ql, qr] add v;
{
	int lc = o * 2, rc = o * 2 + 1;
	if (ql <= L && qr >= R)
		addv[o] += v;
	else
	{
		int M = L + (R - L) / 2;
		if (ql <= M)
			update(lc, L, M);
		if (qr > M)
			update(rc, M + 1, R);
	}
	maintain(o, L, R);
}

LL _min, _max, _sum;

void query(int o, int L, int R, LL add = 0) //get min, max, sum in [ql, qr]
{
	if (ql <= L && qr >= R)
	{
		_sum += sumv[o] + add * (R - L + 1);
		_min = min(_min, minv[o] + add);
		_max = max(_max, maxv[o] + add);
	}
	else
	{
		int M = L + (R - L) / 2;
		if (ql <= M)
			query(o * 2, L, M, add + addv[o]);
		if (qr > M)
			query(o * 2 + 1, M + 1, R, add + addv[o]);
	}
}
struct P { int x, y; LL a, b; } c[maxn];

int main()
{
	for (int n; ~scanf("%d", &n); )
	{
		for (int i = 0; i < n; i++)
			scanf("%d%d%lld%lld", &c[i].x, &c[i].y, &c[i].a, &c[i].b);
		sort(c, c + n, [](P a, P b) { return a.y < b.y; });
		c[n] = {-1, -1, -1, -1};
		int _ = 2;
		for (int i = 0; i < n; i++)
			c[i].y = c[i].y == c[i + 1].y ? _ : _++;
		sort(c, c + n, [](P a, P b) { return a.x < b.x || (a.x == b.x && a.y > b.y); });
		memset(maxv, 0, sizeof(LL) * (_ * K)), memset(addv, 0, sizeof(LL) * (_ * K));
		memset(minv, 0, sizeof(LL) * (_ * K)), memset(sumv, 0, sizeof(LL) * (_ * K));
		for (int i = 0; i < n; i++)
		{
			LL __;
			ql = 1, qr = c[i].y, _max = 0, query(1, 1, _), __ = _max;
			ql = c[i].y, qr = c[i].y, _max = 0, query(1, 1, _);
			ql = c[i].y, qr = c[i].y, v = max(0LL, __ + c[i].b - _max), update(1, 1, _);
			ql = 1, qr = c[i].y - 1, v = c[i].a, update(1, 1, _);
			ql = c[i].y + 1, qr = _, v = c[i].b, update(1, 1, _);
		}
		printf("%lld\n", maxv[1]);
	}
	return 0;
}
