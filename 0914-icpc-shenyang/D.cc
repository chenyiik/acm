#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef long long LL;
const LL mod = LL(1e9) + 7;
void add(int &a, LL b) { a = (a + b) % mod; }
void sub(int &a, LL b) { a = (a - b + mod * mod) % mod; }

const int maxn = int(1e4) + 7;
struct P { int v, d; };
vector<P> G[maxn];
int sz[maxn][3], val[maxn][3], ans[3];

void dfs(int u, int fa)
{
	sz[u][0]++;
	for (P q : G[u]) if (q.v != fa)
	{
		dfs(q.v, u);
		for (int i = 0; i < 3; i++)
		{
			int j = (q.d + i) % 3;
			LL t = sz[q.v][i];
			add(val[u][j], val[q.v][i] + q.d * t);
			sz[u][j] += t;
		}
	}
}

void dfs(int u, int fa, const int cur[], const int sur[])
{
	for (int i = 0; i < 3; i++) add(ans[i], cur[i]);
	for (P q : G[u]) if (q.v != fa)
	{
		int hlf[3], hlg[3]; memcpy(hlf, cur, sizeof(hlf));
		for (int i = 0; i < 3; i++)
		{
			int j = (q.d + i) % 3;
			LL t = sz[q.v][i];
			sub(hlf[j], val[q.v][i] + q.d * t);
			hlg[j] = sur[j] - t;
		}
		int nxt[3]; memcpy(nxt, val[q.v], sizeof(nxt));
		int nxs[3]; memcpy(nxs, sz[q.v], sizeof(nxs));
		for (int i = 0; i < 3; i++)
		{
			int j = (q.d + i) % 3;
			add(nxt[j], hlf[i] + q.d * LL(hlg[i]));
			add(nxs[j], hlg[i]);
		}
		dfs(q.v, u, nxt, nxs);
	}
}

int main()
{
	for (int n; ~scanf("%d", &n); )
	{
		for (int i = 0; i < n; i++) G[i].clear();
		for (int i = 1; i < n; i++)
		{
			int u, v, d; scanf("%d%d%d", &u, &v, &d);
			G[u].push_back({v, d}), G[v].push_back({u, d});
		}
		memset(sz, 0, sizeof(sz[0]) * n);
		memset(val, 0, sizeof(val[0]) * n);
		memset(ans, 0, sizeof(ans));
		dfs(0, -1), dfs(0, -1, val[0], sz[0]);
		printf("%d %d %d\n", ans[0], ans[1], ans[2]);
	}
	return 0;
}
