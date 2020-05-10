#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <utility>

using namespace std;

const int maxn = (200000 + 10) * 4; //from 1 to n, 4*n<maxn
int ql, qr, v;
int _min, _max, _sum;
void update(int o, int L, int R); //let [ql, qr] add v;
void query(int o, int L, int R, int add); //get min, max, sum in [ql, qr]

long long a[maxn];

int main()
{
	int n, m; scanf("%d%d", &n, &m);
	v = 1;
	while (m--)
		scanf("%d%d", &ql, &qr), update(1, 1, n);
	for (int i = 1; i <= n; i++)
		ql = qr = i, _sum = 0, query(1, 1, n, 0), a[i] = _sum;
	sort(a + 1, a + n + 1);
	long long ans = 0;
	for (int i = 1; i <= n; i++)
		ans += i * a[i];//, cout << a[i].first << endl;
	printf("%lld\n", ans);
	return 0;
}

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
