#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>

using namespace std;

const int maxn = 50005;

stack<int> S;
vector<int> G[maxn];
int pre[maxn], lowlink[maxn], sccno[maxn], dfs_clock, scc_cnt;

void dfs(int u)
{
	pre[u] = lowlink[u] = ++dfs_clock;
	S.push(u);
	for (int i = 0; i < G[u].size(); i++)
	{
		int v = G[u][i];
		if (!pre[v])
		{
			dfs(v);
			lowlink[u] = min(lowlink[u], lowlink[v]);
		}
		else if (!sccno[v])
			lowlink[u] = min(lowlink[u], pre[v]);
	}
	if (lowlink[u] == pre[u])
	{
		scc_cnt++;
		for ( ; ; )
		{
			int x = S.top();
			S.pop();
			sccno[x] = scc_cnt;
			if (x == u)
				break;
		}
	}
}

void find_scc(int n)
{
	dfs_clock = scc_cnt = 0;
	memset(sccno, 0, sizeof(sccno));
	memset(pre, 0, sizeof(pre));
	for (int i = 0; i < n; i++)
		if (!pre[i])
			dfs(i);
}

vector<int> ST[maxn];

int main()
{
	int n, m;
	scanf("%d%d", &n, &m);
	while (m--)
	{
		int a, b, t;
		scanf("%d%d%d", &a, &b, &t);
		a--, b--;
		if (t == 1)
			G[a].push_back(b);
		else if (t == 2)
		{
			G[a].push_back(b);
			G[b].push_back(a);
		}
	}
	find_scc(n);
	for (int i = 0; i < n; i++)
		ST[sccno[i]].push_back(i + 1);
	int ans = 0;
	for (int i = 1; i < n; i++)
		if (ST[i].size() > ST[ans].size())
			ans = i;
	printf("%d\n", ST[ans].size());
	for (auto i : ST[ans])
		printf("%d ", i);
	puts("");
	return 0;
}
