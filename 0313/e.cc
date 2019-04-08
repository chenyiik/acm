#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

const int mov[][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
int is_mov[55][55][4];
int get_key[55][55];
bool vis[55][55][2048];

struct P { int x, y, key, step; };

int main()
{
	for (int n, m, p; ~scanf("%d%d%d", &n, &m, &p); )
	{
		memset(is_mov, -1, sizeof(is_mov));
		for (int i = 1; i <= n; i++)
			is_mov[i][1][2] = is_mov[i][m][3] = 0;
		for (int i = 1; i <= m; i++)
			is_mov[1][i][0] = is_mov[n][i][1] = 0;

		int k = 0;
		scanf("%d", &k);
		for (int i = 0; i < k; i++)
		{
			int x0, y0, x1, y1, g;
			scanf("%d%d%d%d%d", &x0, &y0, &x1, &y1, &g);
			if (x0 == x1)
			{
				if (y0 < y1)
					swap(y0, y1);
				is_mov[x0][y0][2] = is_mov[x1][y1][3] = g;
			}
			else
			{
				if (x0 < x1)
					swap(x0, x1);
				is_mov[x0][y0][0] = is_mov[x1][y1][1] = g;
			}
		}

		memset(get_key, 0, sizeof(get_key));
		int s = 0;
		scanf("%d", &s);
		for (int i = 0; i < s; i++)
		{
			int x, y, g;
			scanf("%d%d%d", &x, &y, &g);
			get_key[x][y] |= (1 << g);
		}

		queue<P> Q;
		int bbb = false;
		memset(vis, 0, sizeof(vis));
		Q.push({1, 1, get_key[1][1], 0});
		vis[1][1][get_key[1][1]] = true;
		while (!Q.empty())
		{
			const P &u = Q.front();
			Q.pop();
			if (u.x == n && u.y == m)
			{
				printf("%d\n", u.step);
				bbb = true;
				break;
			}
			for (int i = 0; i < 4; i++)
			{
				if (!is_mov[u.x][u.y][i])
					continue;
				if (!~is_mov[u.x][u.y][i] || u.key & (1 << is_mov[u.x][u.y][i]))
				{
					int x = u.x + mov[i][0], y = u.y + mov[i][1];
					int key = u.key | get_key[x][y];
					if (vis[x][y][key])
						continue;
					Q.push({x, y, key, u.step + 1});
					vis[x][y][key] = true;
				}
			}
		}
		if (!bbb)
			puts("-1");
	}
	return 0;
}

