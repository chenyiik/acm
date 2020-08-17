#include "cyc.h"

//segment add

const int maxn = 200000 + 10;
int minv[maxn], maxv[maxn], sumv[maxn], addv[maxn];

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

int ql, qr, v;

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

int _min, _max, _sum;

void query(int o, int L, int R, int add) //get min, max, sum in [ql, qr]
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
