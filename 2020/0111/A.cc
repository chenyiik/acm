#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int maxn = int(1e5) + 5;
vector<int> v[maxn];

int deep[maxn], sum[2], k, chd[maxn], ans[2], tot[2], tag[maxn], sz[2];
bool vis[maxn];
long long LLsum[2];

void dfs(int u, int fa, int dep)
{
	sum[k] += deep[u] = dep;
	vis[u] = chd[u] = 1;
	sz[k]++;
	tag[u] = k;
	for (int i : v[u]) if (i != fa)
	{
		dfs(i, u, dep + 1);
		chd[u] += chd[i];
	}
}

void dfs(int u, int fa)
{
	vis[u] = true;
	LLsum[k] += sum[k];
	if (sum[k] < tot[k])
		ans[k] = u, tot[k] = sum[k];
	for (int i : v[u]) if (i != fa)
	{
		sum[k] += sz[k] - 2 * chd[i];
		dfs(i, u);
		sum[k] -= sz[k] - 2 * chd[i];
	}
}

int main()
{
	int n, x, y; scanf("%d", &n);
	for (int i = 0; i < n - 2; i++) scanf("%d%d", &x, &y), v[x].push_back(y), v[y].push_back(x);

	for (int i = 1; i <= n; i++) if (!vis[i]) dfs(i, 0, 0), k ^= 1;

	memset(vis, 0, sizeof(vis)), memset(tot, 0x7f, sizeof(tot));
	for (int i = 1; i <= n; i++) if (!vis[i]) dfs(i, 0), k ^= 1;

	memset(vis, 0, sizeof(vis)); memset(sum, 0, sizeof(sum)); memset(sz, 0, sizeof(sz));
	long long fuck = 0;
	for (int i = 0; i < 2; i++) dfs(ans[i], 0, 0), k ^= 1, fuck += LLsum[i] / 2;
	//for (int i = 1; i <= n; i++)
		//cout << i << ' ' << deep[i] << ' ' << tag[i] << endl;
	//cout << '\t' << sz[0] << '\t' << sz[1] << endl;
	//cout << '\t' << sum[0] << '\t' << sum[1] << endl;
	for (int i = 1; i <= n; i++) if (tag[i] == 0)
	{
		int retag = 1; //tag[i] ^ 1;
		fuck += (deep[i] + 1) * sz[retag] + sum[retag];
		//cout << i << ' ' << retag << ' ' << (deep[i] + 1) * sz[retag] + sum[retag] << endl;
	}
	printf("%lld\n", fuck);
	return 0;
}
