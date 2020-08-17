#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <set>
#include <map>
#include <vector>

using namespace std;

typedef long long LL;
struct P { LL v, d; bool operator<(P o) const { return d < o.d; }};

const int maxn = int(1e5) + 15;
vector<P> G[maxn];
int query[maxn];
LL ans[maxn];

int main()
{
	int _; scanf("%d", &_);
	while (_--)
	{
		LL n, m, k; scanf("%lld%lld%lld", &n, &m, &k);
		for (int i = 1; i <= n; i++) G[i].clear();
		for (int i = 1; i <= m; i++) {
			LL u, v, d; scanf("%lld%lld%lld", &u, &v, &d);
			G[u].push_back({v, d});
		}
		int maxk = 0;
		for (int i = 0; i < k; i++)
			scanf("%d", &query[i]), maxk = max(maxk, query[i]);
		multiset<P> M;
		for (int i = 1; i <= n; i++)
		{
			sort(G[i].begin(), G[i].end());
			for (P j : G[i])
			{
				M.insert(j);
				while (M.size() > unsigned(maxk))
				{
					auto it = M.end();
					M.erase(--it);
				}
			}
		}
		for (int i = 1; i <= maxk; i++)
		{
			P p = *M.begin();
			M.erase(M.begin());
			ans[i] = p.d;
			if (i == maxk)
				break;
			for (P j : G[p.v])
			{
				P q = {j.v, j.d + p.d};
				if (M.size() >= maxk - i && q.d >= M.rbegin()->d)
					break;
				while (M.size() >= maxk - i)
				{
					auto it = M.end();
					M.erase(--it);
				}
				M.insert(q);
			}
		}
		for (int i = 0; i < k; i++)
			printf("%lld\n", ans[query[i]]);
	}
	return 0;
}
