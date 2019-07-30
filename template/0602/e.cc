#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef long long LL;

const int maxn = (int)1e5 + 10;
vector<LL> v[maxn];

int main()
{
	int t = 0;
	scanf("%d", &t);
	while (t--)
	{
		int n;
		scanf("%d", &n);
		for (int i = 1; i <= n; i++)
			v[i].clear();
		for (int i = 1; i < n; i++)
		{
			int x, y, w;
			scanf("%d%d%d", &x, &y, &w);
			v[x].push_back(w);
			v[y].push_back(w);
		}
		for (int i = 1; i <= n; i++)
			sort(v[i].begin(), v[i].end());
		LL ans = 0;
		for (int i = 1; i <= n; i++) if (v[i].size() > 1)
		{
			LL bns = 0;
			for (LL j : v[i])
				bns += j;
			bns += v[i][0] * (v[i].size() - 2);
			ans += bns;
		}
		printf("%lld\n", ans);
	}
	return 0;
}
