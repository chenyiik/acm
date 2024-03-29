#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

const int maxn = int(5e5) + 5;
vector<int> G[maxn];
bool vis[maxn];
int color[maxn];
enum { white, red, bule };

int check(int fa)
{
	queue<int> Q;
	Q.push(fa);
	color[fa] = red;
	bool flag = true;
	while (!Q.empty())
	{
		int u = Q.front(); Q.pop();
		for (int v : G[u])
		{
			if (color[v] == color[u])
				return true;
			if (color[v] == white)
			{
				Q.push(v);
				color[v] = color[u] ^ red ^ bule;
				if (color[v] == bule)
					flag = false;
			}

		}
	}
	return flag;
}

void mark(int fa)
{
	queue<int> Q;
	Q.push(fa);
	vis[fa] = true;
	while (!Q.empty())
	{
		int u = Q.front(); Q.pop();
		for (int v : G[u]) if (!vis[v])
		{
			Q.push(v);
			vis[v] = true;
		}
	}
}

int main()
{
	int n, m; scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++)
	{
		int x, y; scanf("%d%d", &x, &y);
		G[x].push_back(y), G[y].push_back(x);
	}
	int one = 0, two = 0, zero = 0;
	for (int i = 1; i <= n; i++) if (!vis[i])
	{
		if (check(i)) one++;
		else two++;
		mark(i);
		if (G[i].size() == 0)
			zero++;
	}
	//cout << one << ' ' << two << endl;
	if (one == 0)
	{ 
		printf("%d\n", two);
	}
	else 
	{
		if (one == zero)
			printf("%d\n", one + two);
		else
			printf("%d\n", one + two - 1);
	}
	return 0;
}
