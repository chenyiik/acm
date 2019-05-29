#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

bool a[40][55][55], c[55][55];
bool vis[55];
int dis[55];

int main()
{
	int n = 0, m = 0;
	scanf("%d%d", &n, &m);
	while (m--)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		a[0][x][y] = true;
	}
	for (int k = 0; k <= 30; k++)
	{
		for (int u = 1; u <= n; u++)
			for (int v = 1; v <= n; v++) if (a[k][u][v])
				for (int w = 1; w <= n; w++) if (a[k][v][w])
					a[k + 1][u][w] = true;
	}
	for (int u = 0; u <= n; u++)
		for (int v = 0; v <= n; v++)
			for (int i = 0; i <= 31; i++)
				c[u][v] |= a[i][u][v];
	queue<int> Q;
	Q.push(1);
	dis[1] = 0;
	vis[1] = true;
	while (!Q.empty())
	{
		int u = Q.front();
		Q.pop();
		for (int i = 1; i <= n; i++) if (!vis[i] && c[u][i])
		{
			Q.push(i);
			dis[i] = dis[u] + 1;
			vis[i] = true;
		}
		if (vis[n])
			break;
	}
	printf("%d\n", dis[n]);
	return 0;
}
