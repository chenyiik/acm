#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>

using namespace std;

typedef long long LL;

const int maxn = 300005, mod = 998244353;
vector<int> v[maxn];
int vis[maxn];
LL ans = 1;

LL pow_mod(LL a, LL p, LL n = mod);
LL mul(LL a, LL b, LL n = mod) { return a * b % n; }

int dfs(int u, int fa, int k)
{
	//cout << u << endl;
	if (vis[u])
	{
		ans = mul(ans, pow_mod(2, k - vis[u]) - 1);
		//cout << u << ' ' << vis[u] << endl;
		return vis[u];
	}
	int ret = vis[u] = k;
	vis[u] = k;
	for (int i : v[u]) if (i != fa && vis[i] != -1)
	{
		int d = dfs(i, u, k + 1);
		if (d > vis[u])
			ans = mul(ans, 2);//, cout << "x2" << endl;
		else
			ret = min(ret, d);
	}
	vis[u] = -1;
	//cout << u << ' ' << ret << endl;
	return ret;
}

int main()
{
	int n, m; scanf("%d%d", &n, &m);
	while (m--)
	{
		int x, y; scanf("%d%d", &x, &y);
		v[x].push_back(y);
		v[y].push_back(x);
	}
	for (int i = 1; i <= n; i++) if (!vis[i])
		dfs(i, 0, 1);
	printf("%lld\n", ans);
	return 0;
}

LL pow_mod(LL a, LL p, LL n)
{
	if (p == 0)
		return 1;
	LL ans = pow_mod(a, p / 2, n);
	ans = ans * ans % n;
	if (p % 2 == 1)
		ans = ans * a % n;
	return ans;
}
