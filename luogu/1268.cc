#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 35;

int main()
{
	for (int n; ~scanf("%d", &n) && n; )
	{
		static int a[N][N];
		for (int i = 1; i <= n; i++)
		{
			a[i][i] = 0;
			for (int j = i + 1; j <= n; j++)
			{
				scanf("%d", &a[i][j]);
				a[j][i] = a[i][j];
			}
		}
		static vector<int> G[N * 100];
		static int dist[N * 100][N];
		static int u[N];
		int nodes = 0, edges = 0;
		u[1] = 0, u[2] = a[1][2];
		if (a[1][2] != 0)
		{
			nodes += a[1][2];
			G[0].push_back(1);
			G[a[1][2]].push_back(a[1][2] - 1);
			dist[0][1] = dist[a[1][2]][2] = 0;
			dist[0][2] = dist[a[1][2]][1] = a[1][2];
			for (int i = 1; i < a[1][2]; i++)
			{
				G[i].push_back(i - 1);
				G[i].push_back(i + 1);
				dist[i][1] = i;
				dist[i][2] = a[1][2] - i;
			}
		}
		else
		{
			nodes++;
			dist[0][1] = dist[0][2] = 0;
		}
		for (int i = 3; i <= n; i++)
		{

		}
		printf("%d\n", edges);
	}
	return 0;
}
