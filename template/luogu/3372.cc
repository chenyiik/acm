#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

namespace cyc
{
	typedef long long LL;

	const int maxN = 131072;

	LL sumv[maxN * 2];
	LL addv[maxN * 2];

	void maintain(int o, int L, int R)
	{
		int lc = o * 2, rc = o * 2 + 1;
		sumv[o] = 0;
		if (R > L)
			sumv[o] = sumv[lc] + sumv[rc];
		sumv[o] += addv[o] * (R - L + 1);
	}

	int y1, y2;
	LL v;
	void update(int o, int L, int R)
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
		maintain(o, L, R);
	}

	LL _sum;
	void query(int o, int L, int R, LL add)
	{
		if (y1 <= L && y2 >= R)
			_sum += sumv[o] + add * (R - L + 1);
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
		int n, m;
		scanf("%d%d", &n, &m);
		for (int i = 1; i <= n; i++)
		{
			scanf("%lld", &v);
			y1 = y2 = i;
			update(1, 1, maxN);
		}
		while (m--)
		{
			int x;
			scanf("%d", &x);
			if (x == 1)
			{
				scanf("%d%d%lld", &y1, &y2, &v);
				update(1, 1, maxN);
			}
			else //if (x == 2)
			{
				scanf("%d%d", &y1, &y2);
				_sum = 0;
				query(1, 1, maxN, 0);
				printf("%lld\n", _sum);
			}
		}
		return 0;
	}
}

int main() { return cyc::main(); }
