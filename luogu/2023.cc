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

	void pushdown(int o)
	{
	}

	void update_add(int o = 1, int L = 1, int R = maxN)
	{
	}

	void update_mul(int o = 1, int L = 1, int R = maxN)
	{
	}

	LL _sum;
	void query(int o = 1, int L = 1, int R = maxN)
	{

	}

	int main()
	{
		int n;
		scanf("%d%lld", &n, &mod);
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
