#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef long long ll;

const int maxn = int(2e5) + 5;
vector<int> v[maxn];
int w[maxn], n;
ll ans;

ll dfs(int u, int fa)
{
	w[u] = 1;
	for (auto i : v[u])
		if (i != fa)
			w[u] += dfs(i, u);
	return w[u];
}

ll dfs(int u, int fa, int deep)
{
	ll ans1 = deep;
	for (auto i : v[u])
		if (i != fa)
			ans1+= dfs(i, u, deep + 1);
	return ans1;
}

void dfs2(int u, int fa, ll wd)
{
	ans = max(ans, wd);
	for (auto i : v[u])
		if (i != fa)
			dfs2(i, u, wd - w[i] + (n - w[i]));
}

int main()
{
	scanf("%d", &n);
	for (int i = 1; i < n; i++)
	{
		int l, r;
		scanf("%d%d", &l, &r);
		v[l].push_back(r);
		v[r].push_back(l);
	}
	dfs(1, 0);
	dfs2(1, 0, dfs(1, 0, 1));
	printf("%lld\n", ans);
	return 0;
}
