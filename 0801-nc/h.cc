#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int maxn = int(1e5) + 5, maxm = 30;
vector<int> G[maxm]; bool vis[maxm];
char t[5], s[maxn], ans[maxn];
vector<int> U[maxn], V[maxn];
vector<bool> H[maxm];
int tot[maxn], g[maxn], len, n, m, node, S[maxn], top;

int main() 
{
	scanf("%d%d", &n, &m);
	for (int k = 0; k < m * (m - 1) / 2; k++)
	{
		scanf("%s%d", t, &len);
		if (len > 0) scanf("%s", s);
		int x = t[0] - 'a', y = t[1] - 'a', xi = -1, yi = -1;
		for (int i = 0; i < len; i++)
		{
			int c = s[i] - 'a', ci = c == x ? ++xi : ++yi;
			if (!vis[c]) 
			{
				g[node] = c; 
				G[c].push_back(node++);
				H[c].push_back(false);
			}
			if (i > 0)
			{
				int d = s[i - 1] - 'a';
				int di = c == d ? ci - 1 : ci ^ xi ^ yi;
				if (c == d && vis[c] && H[d][di])
					continue;
				V[G[d][di]].push_back(G[c][ci]);
				U[G[c][ci]].push_back(G[d][di]);
				if (c == d)
					H[d][di] = true;
			}
		}
		vis[x] = vis[y] = true;
	}
	/*
	for (int i = 0; i < node; i++)
	{
		//cout << i << '\t';
		for (auto j : V[i])
			if (j < 0 || j >= node)
				while (1)
					;
			//cout << j << ' ' ;
		//cout << endl;
	}
	*/
	if (node != n)
		return puts("-1"), 0;
	for (int i = 0; i < node; i++)
		S[top++] = i;
	for (int i = 0; i < node; i++)
	{
		int nod = -1;
		while (top)
		{
			int u = S[--top];
			if ((int)U[u].size() == tot[u])
			{
				if (nod == -1)
					nod = u;
				else
					return puts("-1"), 0;
			}
		}
		if (nod == -1) return puts("-1"), 0;
		ans[i] = g[nod] + 'a';
		for (auto i : V[nod])
			S[top++] = i, tot[i]++;
	}
	puts(ans);
	return 0;
}
