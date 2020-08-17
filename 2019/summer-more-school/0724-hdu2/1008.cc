#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

typedef long long LL;
const LL maxn = 500 + 10;
LL oo = 0x3fffffffffffffff;

struct Edge { LL from, to, cap, flow; };

struct Dinic
{
	LL n, m, s, t;
	vector<Edge> edges;
	vector<LL> G[maxn];
	bool vis[maxn];
	LL d[maxn];
	LL cur[maxn];

	void init()
	{
		n = m = s = t = 0;
		edges.clear();
		for (int i = 0; i < maxn; i++) G[i].clear();
		memset(vis, 0, sizeof(vis));
		memset(d, 0, sizeof(d));
		memset(cur, 0, sizeof(cur));
	}

	void AddEdge(LL from, LL to, LL cap)
	{
		edges.push_back((Edge){from, to, cap, 0});
		edges.push_back((Edge){to, from, 0, 0});
		m = edges.size();
		G[from].push_back(m - 2);
		G[to].push_back(m - 1);
	}

	bool BFS()
	{
		memset(vis, 0, sizeof(vis));
		queue<LL> Q;
		Q.push(s);
		d[s] = 0;
		vis[s] = 1;
		while (!Q.empty())
		{
			LL x = Q.front();
			Q.pop();
			for (int i = 0; i < G[x].size(); i++)
			{
				Edge &e = edges[G[x][i]];
				if (!vis[e.to] && e.cap > e.flow)
				{
					vis[e.to] = 1;
					d[e.to] = d[x] + 1;
					Q.push(e.to);
				}
			}
		}
		return vis[t];
	}

	LL DFS(LL x, LL a)
	{
		if (x == t || a == 0)
			return a;
		LL flow = 0, f;
		for (LL &i = cur[x]; i < G[x].size(); i++)
		{
			Edge &e = edges[G[x][i]];
			if (d[x] + 1 == d[e.to] && (f = DFS(e.to, min(a, e.cap - e.flow))) > 0)
			{
				e.flow += f;
				edges[G[x][i] ^ 1].flow -= f;
				flow += f;
				a -= f;
				if (a == 0)
					break;
			}
		}
		return flow;
	}

	LL Maxflow()
	{
		LL flow = 0;
		while (BFS())
		{
			memset(cur, 0, sizeof(cur));
			flow += DFS(s, oo);
		}
		return flow;
	}
}M;

int main()
{
	for (LL n, m; ~scanf("%lld%lld", &n, &m); )
	{
		M.init(); M.n = n + 2, M.s = 0, M.t = n + 1;
		LL tot = 0;
		while (m--)
		{
			LL u, v, a, b, c; 
			scanf("%lld%lld%lld%lld%lld", &u, &v, &a, &b, &c);
			tot += a + b + c;
			M.AddEdge(M.s, u, a + b);
			M.AddEdge(M.s, v, a + b);
			M.AddEdge(u, M.t, b + c);
			M.AddEdge(v, M.t, b + c);
			M.AddEdge(u, v, a + c - 2 * b);
			M.AddEdge(v, u, a + c - 2 * b);
		}
		printf("%lld\n", tot - M.Maxflow() / 2);
	}
	return 0;
}
