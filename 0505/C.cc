#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

typedef long long LL;

int main()
{
	int T; scanf("%d", &T);
	while (T--)
	{
		int n, k; scanf("%d%d", &n, &k);
		map<LL, LL> M;
		for (int i = -n; i <= n; i++)
		{
			for (int j = -n; j <= n; j++)
			{
				LL d = i * (i + 1) + j * (j + 1);
				if (M.find(d) == M.end()) M[d] = 1;
				else M[d]++;
			}
		}
		LL ans = 0;
		for (pair<LL, LL> p : M)
		{
			LL i = p.first, j = i * k;
			if (M.find(j) != M.end())
				ans += M[i] * M[j];
		}
		printf("%lld\n", ans);
	}
	return 0;
}
