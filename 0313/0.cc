#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

const int move[][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
int is_move[55][55][4];
int get_key[55][55];
bool vis[55][55][2048];

struct P { int x, y, key; };

int main()
{
	for (int n, m, p; ~scanf("%d%d%d", &n, &m, &p); )
	{
		memset(is_move, -1, sizeof(is_move));
		for (int i = 1; i <= n; i++)
			is_move[i][0][2] = is_move[i][m][3] = 0;
		for (int i = 1; i <= m; i++)
			is_move[0][i][0] = is_move[n][i][1] = 0;

		int k = 0;
		for (int i = 0; i < k; i++)
		{
			int x0, y0, x1, y1, g;
			scanf("%d%d%d%d%d", &x0, &y0, &x1, &y1, &g);
			if (x0 == x1)
			{
				if (y0 < y1)
					swap(y0, y1);
				is_move[x0][y0][2] = is_move[x1][y1][3] = g;
			}
			else
			{
				if (x0 < x1)
					swap(x0, x1);
				is_move[x0][y0][0] = is_move[x1][y1][1] = g;
			}
		}

		memset(get_key, 0, sizeof(get_key));
		int s = 0;
		for (int i = 0; i < s; i++)
		{
			int x, y, g;
			scanf("%d%d%d", &x, &y, &g);
			get_key[x][y] = g;
		}

		queue<P> Q;
		memset(vis, 0, sizeof(vis));
		Q.push({1, 1, 0});
		vis[1][1][0] = true;
		while (!Q.empty())
		{
			const P &u = Q.front();
			Q.pop();
		}
		if (Q.empty())
			puts("-1");
	}
	return 0;
}
