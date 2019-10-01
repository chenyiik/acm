#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

const int maxv = 1000000 + 10;
const int maxlogv = 27;

vector<int> G[maxv], H[maxv];
int root;

int pa[maxlogv][maxv];
int depth[maxv];

void dfs(int v, int p, int d)
{
	pa[0][v] = p;
	depth[v] = d;
	for (int i = 0; i < G[v].size(); i++)
		if (G[v][i] != p)
			dfs(G[v][i], v, d + 1);
}

void init(int V)
{
	dfs(root, -1, 0);
	for (int k = 0; k + 1 < maxlogv; k++)
		for (int v = 0; v < V; v++)
			if (pa[k][v] < 0)
				pa[k + 1][v] = -1;
			else
				pa[k + 1][v] = pa[k][pa[k][v]];
}

int lca(int u, int v)
{
	if (depth[u] > depth[v])
		swap(u, v);
	for (int k = 0; k < maxlogv; k++)
		if ((depth[v] - depth[u]) >> k & 1)
			v = pa[k][v];
	if (u == v)
		return u;
	for (int k = maxlogv - 1; k >= 0; k--)
		if (pa[k][u] != pa[k][v])
		{
			u = pa[k][u];
			v = pa[k][v];
		}
	return pa[0][u];
}

int du[maxv];

int main()
{
	int _; scanf("%d", &_);
	for (int i = 0; i < maxlogv; i++)
		pa[i][0] = -1;
	while (_--)
	{
		int n, __; scanf("%d%d", &n, &__);
		for (int i = 0; i <= n; i++)
		{
			G[i].clear(), H[i].clear();
			du[i] = 0, pa[0][i] = -1, depth[i] = 0;
		}
		while (__--)
		{
			int _, ___; scanf("%d%d", &_, &___);
			G[_].push_back(___), H[___].push_back(_);
			du[_]++;
		}
		vector<int> XD;
		root = 0;
		//for (int i = 1; i <= n; i++) 
			//cout << du[i] << ' ';
		//cout << endl;
		for (int i = 1; i <= n; i++) if (du[i] == 0)
		{
			G[i].push_back(root), H[root].push_back(i);
			XD.push_back(i);
		}
		//cout << '\t' << XD.size() << endl;
		for (int i = 0; i < XD.size(); i++)
		{
			//cout << XD[i] << ' ' ;
			for (int j : H[XD[i]]) if (--du[j] == 0)
				XD.push_back(j);
		}
		//cout << endl;
		//for (int i = 1; i <= n; i++) 
			//cout << du[i] << ' ';
		//cout << endl;
		//cout << '\t' << XD.size() << endl;
		for (int i : XD)
		{
			for (int j : G[i])
				pa[0][i] = (pa[0][i] == -1 ? j : lca(pa[0][i], j));
			depth[i] = depth[pa[0][i]] + 1;
			//cout << 'b' << i << endl;
			for (int j = 0; j + 1 < maxlogv; j++)
			{
				if (pa[j][i] < 0)
					pa[j + 1][i] = -1;
				else
					pa[j + 1][i] = pa[j][pa[j][i]];
				//if (j < 5)
				//	cout << pa[j][i] << ' ';
			}
		//	cout << endl;
		}
		/*
		for (int i = 0; i <= n; i++)
			cout << pa[0][i] << ' ';
		cout << endl;
		*/
		scanf("%d", &__);
		while (__--)
		{
			int ___, ____; scanf("%d%d", &___, &____);
			int _ = lca(___, ____);
			printf("%d\n", depth[___] + depth[____] - depth[_]);
		}
	}
	return 0;
}
