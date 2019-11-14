#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
 
using namespace std;
 
const int maxn = int(1e5) + 10;
vector<int> v[maxn];
bool vis[maxn];
int tot[maxn];
 
struct P 
{ 
	int id, cnt;
	bool operator<(const P &o) const 
	{ 
		return cnt < o.cnt || cnt == o.cnt && rand() % 2 == 0;
	}
};
 
int main()
{
	srand(time(nullptr));
	int n, m; scanf("%d%d", &n, &m);
	while (m--)
	{
		int x, y; scanf("%d%d", &x, &y);
		v[x].push_back(y);
		v[y].push_back(x);
	}
	priority_queue<P> Q;
	//for (int i = 1; i <= n; i++)
	for (int i = n; i > 0; i--)
		Q.push({i, tot[i] = v[i].size()});
	int ans = 0;
	m = n - 1;
	while (m > 0 && !Q.empty())
	{
		int u = Q.top().id, c = Q.top().cnt; Q.pop();
		if (c > tot[u])
			continue;
		vis[u] = true;
		if (tot[u] == m--)
			ans++;
		for (int i : v[u]) if (!vis[i])
			Q.push({i, --tot[i]});
	}
	printf("%d\n", ans);
	return 0;
}
