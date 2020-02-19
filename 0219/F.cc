#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <map>
#include <vector>

using namespace std;

const int maxn = int(2e5) + 5;
int p[maxn];
int n, m;
int find(int x) { return p[x] == x ? x : p[x] = find(p[x]); }
void kruscal();

map<int, int> M;
vector<int> vol[maxn];
int M_r[maxn];
int EDGE = 0;

struct P { int x, y, e; };
vector<P> ans;

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		int m; scanf("%d", &m);
		for (int j = 0; j < m; j++)
		{
			int x; scanf("%d", &x);
			if (M.find(x) == M.end())
				M[x] = EDGE, M_r[EDGE++] = x;
			vol[M[x]].push_back(i);
		}
	}
	kruscal();
	if (ans.size() < n - 1)
		puts("impossible");
	else
		for (auto i : ans)
			printf("%d %d %d\n", i.x, i.y, i.e);
	return 0;
}

void kruscal()
{
	for (int i = 1; i <= n; i++) 
		p[i] = i;
	for (int i = 0; i < EDGE; i++)
	{
		if (vol[i].size() < 2)
			continue;
		int u = vol[i][0];
		for (int j = 1; j < vol[i].size(); j++)
		{
			int v = vol[i][j];
			int x = find(u), y = find(v);
			if (x != y)
			{
				p[x] = y;
				ans.push_back({u, v, M_r[i]});
			}
		}
	}
}
