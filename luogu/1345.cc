#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

const int maxn = 200 + 10;
const int oo = 0x3f3f3f3f;

struct Edge { int from, to, cap, flow; };

struct Dinic
{
	int n, m, s, t;
	vector<Edge> edges;
	vector<int> G[maxn];
	bool vis[maxn];
	int d[maxn];
	int cur[maxn];
	
	void AddEdge(int from, int to, int cap)
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
		queue<int> Q;
		Q.push(s);
		d[s] = 0;
		vis[s] = 1;
		while (!Q.empty())
		{
			int x = Q.front();
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

	int DFS(int x, int a)
	{
		if (x == t || a == 0)
			return a;
		int flow = 0, f;
		for (int &i = cur[x]; i < G[x].size(); i++)
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

	int Maxflow(int s, int t)
	{
		this->s = s;
		this->t = t;
		int flow = 0;
		while (BFS())
		{
			memset(cur, 0, sizeof(cur));
			flow += DFS(s, oo);
		}
		return flow;
	}
};

vector<int> G[maxn];

int main()
{
	int n, m, s, t;
	scanf("%d%d%d%d", &n, &m, &s, &t);
	for (int i = 0; i < m; i++)
	{
		int u, v;
		scanf("%d%d", &u, &v);
		G[u].push_back(v);
		G[v].push_back(u);
	}
	Dinic D;
	D.n = n * 2;
	for (int i = 1; i <= n; i++)
	{
		D.AddEdge(i, i + n, 1);
		for (int j : G[i])
		{
			D.AddEdge(j + n, i, oo / 2);
			D.AddEdge(i + n, j, oo / 2);
		}
	}
	printf("%d\n", D.Maxflow(s + n, t));
	return 0;
}
