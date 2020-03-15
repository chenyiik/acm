#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

int v[40], a[10][10];
int tot[40], ans[10][10];
bool vis[10][10], visx[10][10], visy[10][10], visf[40][10];

void print();
int get_x(int i){ return (i%18)/3; }
int get_y(int i){ return (i/18)*3+i%18%3; }

void dfs(int k)
{
	if (k == 36)
		print(), exit(0);
	int x = get_x(k), y = get_y(k), b = k / 6, s = a[x][y];
	for (int i = 1; i <= 6; i++) 
		if (!vis[b][i] && !visx[x][i] && !visy[y][i] 
				&& !visf[s][i] && tot[s] + i <= v[s])
		{
			vis[b][i] = visx[x][i] = visy[y][i] = visf[s][i] = true;
			tot[s] += i;
			ans[x][y] = i;
			dfs(k + 1);
			tot[s] -= i;
			vis[b][i] = visx[x][i] = visy[y][i] = visf[s][i] = false;
		}
}

int main()
{
	int n; scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &v[i]);
	for (int i = 0; i < 6; i++) for (int j = 0; j < 6; j++)
		scanf("%d", &a[i][j]);
	dfs(0);
	return 0;
}

void print()
{
	for (int i = 0; i < 6; i++) for (int j = 0; j < 6; j++)
		printf("%d%c", ans[i][j], " \n"[j == 5]);
}
