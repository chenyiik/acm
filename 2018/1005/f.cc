#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <stack>

using namespace std;

const int maxN = static_cast<int>(1e5) + 7;
vector<int> G[maxN];
struct Edge { int u, v, p, n; } edges[maxN];
struct P { int arv, ti; bool operator<(const P &o) const { return arv < o.arv || (arv == o.arv && ti < o.ti); } };

int main()
{
	int n = 0, m = 0;
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; i++)
	{
		Edge &e = edges[i];
		scanf("%d%d%d%d", &e.u, &e.v, &e.p, &e.n);
		G[e.u].push_back(i);
	}
	Edge f;
	scanf("%d%d%d%d", &f.u, &f.v, &f.p, &f.n);
	if (f.u == f.v)
	{
		puts("0");
		return 0;
	}
	edges[0] = {0, f.u, 0, 0};

	static bool vis[maxN];
	memset(vis, false, sizeof(vis));
	static int pre[maxN];
	memset(pre, 0, sizeof(pre));
	int mark = 0;
	//set<P> Se;
	set<int> Se;
	queue<int> Q;
	Q.push(0);
	//Se.insert({f.u, f.p});
	Se.insert(f.u);
	while (!Q.empty())
	{
		int p = Q.front();
		Q.pop();
		for (int i = 0; i < G[edges[p].v].size(); i++)
		{
			int q = G[edges[p].v][i];
			Edge &e = edges[q];
			//if (vis[q] || edges[p].n > e.p || Se.find({e.v, e.n}) != Se.end())
			//if (vis[q] || edges[p].n > e.p || Se.find(e.v) != Se.end())
			if (vis[q] || edges[p].n > e.p)
				continue;
			Q.push(q);
			vis[q] = true;
			pre[q] = p;
			//Se.insert({e.v, e.n});
			Se.insert(e.v);
			if (e.v == f.v && e.n <= f.n)
			{
				mark = q;
				break;
			}
		}
		if (mark)
			break;
	}

	if (!mark)
		puts("Impossible");
	else
	{
		stack<int> St;
		for (int i = mark; i != 0; i = pre[i])
			St.push(i);
		printf("%d\n", St.size());
		while (!St.empty())
		{
			printf("%d ", St.top());
			St.pop();
		}
		puts("");
	}

	return 0;
}
