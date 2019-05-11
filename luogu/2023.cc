#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

namespace cyc
{
	typedef long long LL;
	LL mod;
	const int maxN = 131072;
	LL addv[maxN * 2], mul[maxN * 2], sumv[maxN * 2];

	void maintain(int o, int L, int R)
	{
		int lc = o * 2, rc = o * 2 + 1;
		sumv[o] = 0;
		if (R > L)
			sumv[o] = (sumv[lc] + sumv[rc]) % mod;
		sumv[o] += addv[o] * (R - L + 1);
		sumv[o] %= mod;
	}

	int y1, y2;
	LL v;

	void update_add(int o = 1, int L = 1, int R = maxN)
	{
		int lc = o * 2, rc = o * 2 + 1;
		if (y1 <= L && y2 >= R)
			addv[o] += v;
		else
		{
			int M = L + (R - L) / 2;
			if (y1 <= M)
				update(lc, L, M);
			if (y2 > M)
				update(rc, M + 1, R);
		}
	}

	void pushdown(int o)
	{
		int lc = o * 2, rc = o * 2 + 1;
		if (mul[o] > 1)
		{
			mul[lc] *= mul[o];
			mul[rc] *= mul[o];
			mul[o] = 1;
		}
	}

	void update_mul(int o = 1, int L = 1, int R = maxN)
	{
		int lc = o * 2, rc = o * 2 + 1;
		if (y1 <= L && y2 >= R)
			setv[o] = v;
		else
		{
			pushdown(o);
			int M = L + (R - L) / 2;
			if (y1 <= M)
				update(lc, L, M);
			else
				maintain(lc, L, M);
			if (y2 > M)
				update(rc, M + 1, R);
			else
				maintain(rc, M + 1, R);
		}
		maintain(o, L, R);
	}

	LL _sum;
	void query(int o = 1, int L = 1, int R = maxN, LL add)
	{
		if (y1 <= L && y2 >= R)
		{
			_sum += sumv[o] + add * (R - L + 1);
		}
		else
		{
			int M = L + (R - L) / 2;
			if (y1 <= M)
				query(o * 2, L, M, add + addv[o]);
			if (y2 > M)
				query(o * 2 + 1, M + 1, R, add + addv[o]);
		}
	}

	int main()
	{
		int n;
		scanf("%d%lld", &n, &mod);
		for (int i = 0; i < maxN * 2; i++)
			mul[i] = 1;
		for (int i = 1; i <= n; i++)
		{
			scanf("%lld", &v);
			y1 = y2 = i;
			update_add();
		}
		int m;
		scanf("%d", &m);
		while (m--)
		{
			int op;
			scanf("%d%d%d", &op, &y1, &y2);
			if (op == 3)
			{
				_sum = 0;
				query();
				printf("%lld\n", _sum);
			}
			else
			{
				scanf("%lld", &v);
				if (op == 2)
					update_add();
				else
					update_mul();
			}
		}
		return 0;
	}
}

int main() { return cyc::main(); }
