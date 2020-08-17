#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

struct Edge { int from, to, dist; };

int gg = 0;

struct SPFA
{
	static const int maxn = 200000;
	int n, m;
	vector<Edge> edges;
	vector<int> G[maxn];
	bool inq[maxn];
	int d[maxn];
	int p[maxn];
	int cnt[maxn];

	void init(int n)
	{
		this->n = n + 1;
	}

	void AddEdge(int from, int to, int dist)
	{
		edges.push_back((Edge){from, to, dist});
		m = edges.size();
		G[from].push_back(m - 1);
	}

	bool spfa()
	{
		queue<int> Q;
		memset(inq, 0, sizeof(inq));
		memset(cnt, 0, sizeof(cnt));
		for (int i = 0; i <= n; i++)
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
} A;

int main()
{
	int n, m;
	scanf("%d%d", &n, &m);
	A.init(n);
	while (m--)
	{
		int q, a, b, c;
		scanf("%d%d%d", &q, &a, &b);
		if (q == 1)
		{
			scanf("%d", &c);
			A.AddEdge(a, b, -c);
		}
		else if (q == 2)
		{
			scanf("%d", &c);
			A.AddEdge(b, a, c);
		}
		else if (q == 3)
		{
			A.AddEdge(a, b, 0);
			A.AddEdge(b, a, 0);
		}
	}
	puts(!A.spfa() ? "Yes" : "No");
}
