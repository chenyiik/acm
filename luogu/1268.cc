#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

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
		memset(dist, -1, sizeof(dist));
		int nodes = 0;
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
			int s = 0, d = 0;
			for (int j = 0; j < nodes; j++)
			{
				d = a[i][1] - dist[j][1];
				bool b = true;
				for (int k = 2; k < i; k++)
				{
					if (a[i][k] - dist[j][k] != d)
					{
						b = false;
						break;
					}
				}
				if (b)
				{
					s = j;
					break;
				}
			}
#ifdef _D
			if (s == 0)
				break;
#endif
			if (d != 0)
			{
				G[s].push_back(nodes);
				for (int j = 0; j < d - 1; j++)
				{
					G[nodes + j].push_back(nodes + j + 1);
					dist[nodes + j][i] = d - j;
					for (int k = 1; k < i; k++)
						dist[nodes + j][k] = dist[nodes + j - 1][k] + 1;
				}
				G[nodes + d - 1].push_back(nodes + d - 1);
				for (int k = 1; k < i; k++)
					dist[nodes + d - 1][k] = dist[nodes + d - 2][k] + 1;
				u[i] = nodes + d - 1;
				dist[nodes + d - 1][i] = 0;
			}
			else
			{
				u[i] = s;
				dist[s][i] = 0;
			}
			queue<int> Q;
			Q.push(s);
			while (!Q.empty())
			{
				int p = Q.front();
				Q.pop();
				for (int j : G[p])
				{
					if (dist[j][i] != -1)
						continue;
					dist[j][i] = dist[p][i] + 1;
					Q.push(j);
				}
			}
			nodes += d;
#ifdef _D
		cout << d << ' ' << s << endl;
#endif
		}
#ifdef _D
		cout << endl;
#endif
		printf("%d\n", nodes - 1);
		for (int i = 0; i < nodes; i++)
			vector<int>().swap(G[i]);
#ifdef _D
		for (int i = 1; i <= n; i++)
			cout << u[i] << ' ';
		cout << endl;
		for (int i = 0; i < nodes; i++)
		{
			cout << i << '\t';
			for (int j = 1; j <= n; j++)
				cout << dist[i][j] << ' ';
			cout << endl << '\t';
			for (int j : G[i])
				cout << j << ' ';
			cout << endl;
		}
#endif
	}
	return 0;
}
