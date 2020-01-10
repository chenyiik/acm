#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int maxn = int(2e5) + 5;
int c[maxn], d[maxn], maxd = 0, mid[maxn];
bool b[maxn];
vector<int> v[maxn], S;

void dfs(int u, int fa)
{
	d[u] = d[fa] + 1;
	if (b[u] && d[u] > maxd)
		maxd = d[u];
	S.push_back(u);
	mid[u] = S[d[u] / 2];
	for (int i : v[u]) if (i != fa)
		dfs(i, u);
	S.pop_back();
}

int main()
{
	int n, m; scanf("%d%d", &n, &m);
	for (int i = 1; i < n; i++)
	{
		int x, y; scanf("%d%d", &x, &y);
		v[x].push_back(y);
		v[y].push_back(x);
	}
	for (int i = 1; i <= m; i++)
		scanf("%d", &c[i]), b[c[i]] = true;
	d[0] = -1;
	dfs(c[1], 0);
	if (maxd % 2 == 1)
		return puts("NO"), 0;
	int k = 0;
	for (int i = 1; i <= m; i++) if (maxd == d[c[i]])
	{
		if (!k)
			k = mid[c[i]];
		else if (k != mid[c[i]])
			return puts("NO"), 0;
	}
	maxd = 0;
	dfs(k, 0);
	for (int i = 1; i <= m; i++)
		if (maxd != d[c[i]])
			return puts("NO"), 0;
	printf("YES\n%d\n", k);
	return 0;
}
