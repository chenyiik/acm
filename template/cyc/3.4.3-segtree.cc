#include "cyc.h"

//segment set

const int maxn = 200000 + 10;
int minv[maxn], maxv[maxn], sumv[maxn], setv[maxn];

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
	minv[o] = setv[o];
	maxv[o] = setv[o];
	sumv[o] = setv[o] * (R - L + 1);
}

void pushdown(int o)
{
	int lc = o * 2, rc = o * 2 + 1;
	if (setv[o] >= 0)
	{
		setv[lc] = setv[rc] = setv[o];
		setv[o] = -1; // no mark
	}
}

int ql, qr, v;

void update(int o, int L, int R) //let [ql, qr] add v;
{
	int lc = o * 2, rc = o * 2 + 1;
	if (ql <= L && qr >= R)
		setv[o] = v;
	else
	{
		pushdown(o);
		int M = L + (R - L) / 2;
		if (ql <= M)
			update(lc, L, M);
		if (qr > M)
			update(rc, M + 1, R);
	}
	maintain(o, L, R);
}

int _min, _max, _sum;

void query(int o, int L, int R) //get min, max, sum in [ql, qr]
{
	if (setv[o] >= 0)
	{
		_sum += setv[o] * (min(R, qr) - max(L, ql) + 1);
		_min = min(_min, setv[o]);
		_max = max(_max, setv[o]);
	}
	else if (ql <= L && qr >= R)
	{
		_sum += sumv[o];
		_min = min(_min, minv[o]);
		_max = max(_max, maxv[o]);
	}
	else
	{
		int M = L + (R - L) / 2;
		if (ql <= M) 
			query(o * 2, L, M);
		if (qr > M)
			query(o * 2 + 1, M + 1, R);
	}
}
