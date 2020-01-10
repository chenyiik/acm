#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int maxn = 5005;
int pre[maxn], nxt[maxn], head, til;

struct P { int value, node; };
vector<P> G[maxn * maxn / 2];
int tot;
int init_trie() { G[tot = 0].clear(); return tot++; }
int new_node() { G[tot].clear(); return tot++; }
void insert_seq()
{
	for (int e = nxt[head], u = 0; e != til; e = nxt[e])
	{
		bool f = false;
		for (int i = 0; i < G[u].size(); i++)
		{
			if (G[u][i].value == e)
			{
				u = G[u][i].node;
				f = true;
				break;
			}
		}
		if (!f)
		{
			int v = new_node();
			P a; a.value = e, a.node = v;
			G[u].push_back(a);
			u = v;
		}
	}
}

int main()
{
	int t; scanf("%d", &t);
	while (t--)
	{
		int n, q; scanf("%d%d", &n, &q);
		head = 0, til = n + 1;
		nxt[head] = til, pre[til] = head;
		for (int i = 1; i <= n; i++)
			pre[i] = nxt[i] = -1;
		init_trie();
		for (int i = 0; i < n; i++)
		{
			int x; scanf("%d", &x);
			if (pre[x] != -1)
			{
				nxt[pre[x]] = nxt[x];
				pre[nxt[x]] = pre[x];
			}
			nxt[x] = nxt[head];
			pre[x] = head;
			pre[nxt[head]] = x;
			nxt[head] = x;
			insert_seq();
		}
		/*
		for (int u = 0; u < tot; u++)
		{
			cout << u << endl;
			for (int i = 0; i < G[u].size(); i++)
				cout << '\t' << G[u][i].value << ' ' <<G[u][i].node << endl;
		}
		*/
		while (q--)
		{
			int m; scanf("%d", &m);
			bool f = true, zero = false;
			for (int u = 0; m--;)
			{
				int x; scanf("%d", &x);
				if (!f)
					continue;
				if (zero && x != 0)
				{
					f = false;
					continue;
				}
				if (x == 0)
				{
					zero = true;
					continue;
				}
				bool g = false;
				for (int i = 0; i < G[u].size(); i++)
				{
					if (G[u][i].value == x)
					{
						u = G[u][i].node;
						g = true;
						break;
					}
				}
				f &= g;
			}
			puts(f ? "Yes" : "No");
		}
	}
	return 0;
}
