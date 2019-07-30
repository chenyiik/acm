#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int mp[][5] = {
	{5, -1, -2, -1, -3},
	{-1, 5, -3, -2, -4},
	{-2, -3, 5, -2, -2},
	{-1, -2, -2, 5, -1},
	{-3, -4, -2, -1, 0}
};

const int pm[4] = {'A', 'C', 'G', 'T'};

void init(int &n, int &m, int a1[], int a2[])
{
	static char s1[105], s2[105];
	scanf("%d%s%d%s", &n, s1 + 1, &m, s2 + 1);
	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (s1[i] == pm[j])
				a1[i] = j;
		}
	}
	for (int i = 1; i <= m; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (s2[i] == pm[j])
				a2[i] = j;
		}
	}
}

int f[105][105];
bool vis[105][105];
int a[105], b[105];

int dfs(int i, int j)
{
	if (vis[i][j])
		return f[i][j];
	vis[i][j] = true;
	/*
	cout << i << ' ' << j << ' ';
	if (j > 0)
		cout << mp[4][b[j]] << ' ';
	if (i > 0)
		cout << mp[a[i]][4] << ' ';
	if (i > 0 && j > 0)
		cout << mp[a[i]][b[j]] << ' ';
	cout << endl;
	*/
	if (i == 0)
		return f[i][j] = dfs(0, j - 1) + mp[4][b[j]];
	else if (j == 0)
		return f[i][j] = dfs(i - 1, 0) + mp[a[i]][4];
	else
		return f[i][j] = max(dfs(i - 1, j - 1) + mp[a[i]][b[j]], 
				max(dfs(i, j - 1) + mp[4][b[j]], dfs(i - 1, j) + mp[a[i]][4]));
}

int main()
{
	int n = 0, m = 0;
	init(n, m, a, b);
	vis[0][0] = true;
	//for (int i = 1; i <= n; i++)
		//cout << a[i] << ' ';
	//cout << endl;
	//for (int j = 1; j <= m; j++)
		//cout << b[j] << ' ';
	//cout << endl;
	//for (int i = 0; i <= n; i++)
	//{
		//for (int j = 0; j <= m; j++)
			//cout << f[i][j] << ' ';
		//cout << endl;
	//}
	printf("%d\n", dfs(n, m));
	return 0;
}
