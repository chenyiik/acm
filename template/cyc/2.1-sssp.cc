#include "cyc.h"

const int maxn = 100000 + 10;

struct Edge { int from, to, dist; };

struct HeapNode
{
	int d, u;
	bool operator<(const HeapNode &rhs) const { return d > rhs.d; }
};

struct Dijkstra
{
	int n, m;
	vector<Edge> edges;
	vector<int> G[maxn];
	bool done[maxn];
	int d[maxn];
	int p[maxn];

	void init(int n)
	{
		this->n = n;
		for (int i = 0; i < n; i++)
			G[i].clear();
		edges.clear();
	}

	void AddEdge(int from, int to, int dist)
	{
		edges.push_back((Edge){from , to, dist});
		m = edges.size();
		G[from].push_back(m - 1);
	}

	void dijkstra(int s)
	{
		priority_queue<HeapNode> Q;
		for (int i = 0; i < n; i++)
			d[i] = oo;
		d[s] = 0;
		memset(done, 0, sizeof(done));
		Q.push((HeapNode){0, s});
		while (!Q.empty())
		{
			HeapNode x = Q.top();
			Q.pop();
			int u = x.u;
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
};

struct BellmanFord
{
	int n, m;
	vector<Edge> edges;
	vector<int> G[maxn];
	bool inq[maxn];
	int d[maxn];
	int p[maxn];
	int cnt[maxn];

	void init(int n)
	{
		this->n = n;
		for (int i = 0; i < n; i++)
			G[i].clear();
		edges.clear();
	}

	void AddEdge(int from, int to, int dist)
	{
		edges.push_back((Edge){from, to, dist});
		m = edges.size();
		G[from].push_back(m - 1);
	}

	bool negativeCycle()
	{
		queue<int> Q;
		memset(inq, 0, sizeof(inq));
		memset(cnt, 0, sizeof(cnt));
		for (int i = 0; i < n; i++)
		{
			d[i] = 0;
			inq[0] = true;
			Q.push(i);
		}

		while (!Q.empty())
		{
			int u = Q.front();
			Q.pop();
			inq[u] = false;
			for (int i = 0; i < G[u].size(); i++)
			{
				Edge &e = edges[G[u][i]];
				if (d[e.to] > d[u] + e.dist)
				{
					d[e.to] = d[u] + e.dist;
					p[e.to] = G[u][i];
					if (!inq[e.to])
					{
						Q.push(e.to);
						inq[e.to] = true;
						if (++cnt[e.to] > n)
							return true;
					}
				}
			}
		}
		return false;
	}
};
