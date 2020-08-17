#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int maxn = int(1e5) + 10;
vector<int> v[maxn];
bool p[maxn];
int ans = 0x7fffffff;
int dep[maxn], dep2[maxn], son[maxn]; 

int dfs0(int u, int uu = 0)
{
	for (int i : v[u])
		if (i != uu)
		{
			int d = dfs0(i, u);
			if (d > -1)
				d++;
			if (d > dep[u])
			{
				dep2[u] = dep[u];
				dep[u] = d, son[u] = i;
			}
			else if (d > dep2[u])
				dep2[u] = d;
		}
	if (p[u])
	{
		if (dep[u] == -1)
			dep[u] = 0, son[u] = u;
		else if (dep2[u] == -1)
			dep2[u] = 0;
	}
	//cout << u << ' ' << dep[u] << ' ' << dep2[u] << ' ' << son[u] << endl;
	return dep[u];
}

void dfs1(int u, int uu = 0, int high = -1)
{
	//cout << u << ' ' << dep[u] << ' ' <<  high << endl;
	if (high != -1 || dep[u] != -1)
		ans = min(ans, max(high, dep[u]));
	for (int i : v[u])
		if (i != uu)
		{
			if (son[u] == i)
			{
				if (high != -1 || dep2[u] != -1)
					dfs1(i, u, 1 + max(high, dep2[u]));
				else
					dfs1(i, u);
			}
			else
			{
				if (high != -1 || dep[u] != -1)
					dfs1(i, u, 1 + max(high, dep[u]));
				else
					dfs1(i, u);
			}
		}
}

int main()
{
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 1; i < n; i++)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		v[x].push_back(y);
		v[y].push_back(x);
	}
	if (m < 1)
		return puts("0"), 0;
	while (m--)
	{
		int k;
		scanf("%d", &k);
		p[k] = true;
	}
	memset(dep, -1, sizeof(dep));
	memset(dep2, -1, sizeof(dep2));
	memset(son, -1, sizeof(son));
	dfs0(1), dfs1(1);
	printf("%d\n", ans);
	return 0;
}
