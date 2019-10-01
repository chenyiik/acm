#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

typedef long long LL;

const LL maxn = LL(1e4) + 10;
const LL oo = 0x3f3f3f3f3f3f3f3fll;

struct Edge 
{ 
	LL from, to, dist, cap, flow;
	Edge() {}
	Edge(LL a, LL b, LL c) : from(a), to(b), dist(c) {}
	Edge(LL a, LL b, LL c, LL d) : from(a), to(b), cap(c), flow(d) {}
};

struct HeapNode
{
	LL d, u;
	bool operator<(const HeapNode &rhs) const { return d > rhs.d; }
};

struct Dijkstra
{
	LL n, m, d[maxn], p[maxn];
	vector<Edge> edges;
	vector<LL> G[maxn];
	bool done[maxn];

	void init(LL n)
	{
		this->n = n;
		for (int i = 0; i < n; i++)
			G[i].clear();
		edges.clear();
	}

	void AddEdge(LL from, LL to, LL dist)
	{
		edges.push_back(Edge(from, to, dist));
		m = edges.size();
		G[from].push_back(m - 1);
	}

	void dijkstra(LL s)
	{
		priority_queue<HeapNode> Q;
		for (int i = 0; i < n; i++)
			d[i] = +oo;
		d[s] = 0;
		memset(done, 0, sizeof(done));
		Q.push((HeapNode){0, s});
		while (!Q.empty())
		{
			HeapNode x = Q.top();
			Q.pop();
			LL u = x.u;
			if (done[u])
				continue;
			done[u] = true;
			for (int i = 0; i < G[u].size(); i++)
			{
				Edge &e = edges[G[u][i]];
				if (d[e.to] > d[u] + e.dist)
				{
					d[e.to] = d[u] + e.dist;
					p[e.to] = G[u][i];
					Q.push((HeapNode){d[e.to], e.to});
				}
			}
		}
	}
} dij;

struct Dinic
{
	LL n, m, s, t, d[maxn], cur[maxn];
	vector<Edge> edges;
	vector<LL> G[maxn];
	bool vis[maxn];

	void init(LL n)
	{
		this->n = n;
		for (int i = 0; i < n; i++)
			G[i].clear();
		edges.clear();
	}

	void AddEdge(LL from, LL to, LL cap)
	{
		edges.push_back(Edge(from, to, cap, 0));
		edges.push_back(Edge(to, from, 0, 0));
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

	LL Maxflow(LL s, LL t)
	{
		this->s = s;
		this->t = t;
		LL flow = 0;
		while (BFS())
		{
			memset(cur, 0, sizeof(cur));
			flow += DFS(s, oo);
		}
		return flow;
	}
} din;

int main()
{
	int t;
	scanf("%d", &t);
	while (t--)
	{
		LL n, m;
		scanf("%lld%lld", &n, &m);
		static Edge e[maxn];
		dij.init(n);
		for (int i = 0; i < m; i++)
		{
			scanf("%lld%lld%lld", &e[i].from, &e[i].to, &e[i].dist);
			dij.AddEdge(--e[i].from, --e[i].to, e[i].dist);
		}
		dij.dijkstra(0);
		din.init(n);
		for (int i = 0; i < m; i++)
			if (dij.d[e[i].from] + e[i].dist == dij.d[e[i].to])
				din.AddEdge(e[i].from, e[i].to, e[i].dist);
		printf("%lld\n", din.Maxflow(0, n - 1));
	}
	return 0;
}
