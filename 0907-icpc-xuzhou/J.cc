#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef long long LL;

void Rd(int &res){
	res=0;
	char c;
	while(c=getchar(),!isdigit(c));
	do{
		res=(res*10)+(c^48);
	}while(c=getchar(),isdigit(c));
}

const int mod = int(1e9) + 7;

LL pow_mod(LL a, LL p, LL n = mod)
{
	if (p == 0)
		return 1;
	LL ans = pow_mod(a, p / 2, n);
	ans = ans * ans % n;
	if (p % 2 == 1)
		ans = ans * a % n;
	return ans;
}

LL inv(LL a, LL n = mod) { return pow_mod(a, n - 2, n); }

const int maxn = int(1e6) + 5;
vector<int> G[maxn];
int dep[maxn];

int dfs1(int u, int fa, int d)
{
	dep[u] = d;
	for (int i : G[u]) if (i != fa)
		dep[u] = max(dep[u], dfs1(i, u, d + 1));
	return dep[u];
}

LL ans = 0;
void dfs2(int u, int fa, int yy)
{
	//cout << u << ' ' << yy << endl;
	LL k = 0, t = 0;
	for (int i : G[u]) if (i != fa)
	{
		k++;
		if (dep[i] == dep[u])
			t++;
	}
	if (k == 0)
		ans = (ans + yy) % mod
	LL temp = (k - t) * inv(k) % mod;
	temp = pow_mod(temp, k);
	temp = (1 - temp + mod) % mod;
	temp = temp * inv(t) % mod;
	temp = temp * yy % mod;
	for (int i : G[u]) if (i != fa && dep[i] == dep[u])
		dfs2(i, u, temp);
}

int main()
{
	int n; Rd(n);
	for (int i = 1; i < n; i++)
	{
		int u, v; Rd(u), Rd(v);
		G[u].push_back(v);
		G[v].push_back(u);
	}
	dfs1(1, 0, 0);
	dfs2(1, 0, 1);
	printf("%lld\n", ans);
	return 0;
}
