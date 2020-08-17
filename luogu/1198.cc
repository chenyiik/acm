#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

namespace cyc
{
	typedef long long LL;

	const LL oo = 0x8000000000000000LL;
	const int maxN = 262144;

	LL maxv[maxN * 2];

	int ql, qr;
	LL query(int o, int L, int R)
	{
		int M = L + (R - L) / 2;
		if (ql <= L && R <= qr)
			return maxv[o];
		LL ans = -oo;
		if (ql <= M)
			ans = max(ans, query(o * 2, L, M));
		if (M < qr)
			ans = max(ans, query(o * 2 + 1, M + 1, R));
		return ans;
	}

	int p;
	LL v;
	void update(int o, int L, int R)
	{
		int M = L + (R - L) / 2;
		if (L == R)
			maxv[o] = v;
		else
		{
			if (p <= M)
				update(o * 2, L, M);
			else
				update(o * 2 + 1, M + 1, R);
			maxv[o] = max(maxv[o * 2], maxv[o * 2 + 1]);
		}
	}

	int main()
	{
		int m, n = 0;
		LL mod, lans = 0;
		scanf("%d%lld", &m, &mod);
		while (m--)
		{
			char s[3];
			LL y;
			scanf("%s%lld", s, &y);
			if (*s == 'A')
			{
				v = (y + lans) % mod;
				p = ++n;
				update(1, 1, maxN);
			}
			else if (*s == 'Q')
			{
				qr = n;
				ql = n - y + 1;
				lans = query(1, 1, maxN);
				printf("%lld\n", lans);
			}
		}
		return 0;
	}
}

int main() { return cyc::main(); }
