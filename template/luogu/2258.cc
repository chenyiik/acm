#include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>

using namespace std;

int n, m, r, c, a[16][17], dp[17][17], g[17], h[17][17];
//int n, m, r, c, a[16][17], dp[65536][17][17], g[65536][17], h[65536][17][17];
bool b[16];

bool f(int d)
{
	int t = 0;
	for (int i = 0; i < n; i++)
	{
		t += d & 1;
		b[i] = d & 1;
		d >>= 1;
	}
	return t == r;
}

void init()
{
	scanf("%d%d%d%d", &n, &m, &r, &c);
	for (int i = 0; i < n; i++)
		for (int j = 1; j <= m; j++)
			scanf("%d", &a[i][j]);
	/*
	for (int i = 0; i < (1 << n); i++)
	{
		if (f(i))
		{
			for (int col = 1; col <= m; col++)
			{
				int k = 0;
				while (!b[k])
					k++;
				for (int j = k + 1; j < n; j++)
					if (b[j])
					{
//cout << j << ' ' << k << ' ' << col << ' ' << a[j][col] << ' ' << a[k][col] << endl;
						g[i][col] += abs(a[j][col] - a[k][col]);
						k = j;
					}
			}
			for (int cla = 1; cla < m; cla++)
				for (int clb = cla + 1; clb <= m; clb++)
					for (int j = 0; j < n; j++)
						if (b[j])
						{
//cout << j << ' ' << cla << ' ' << clb << ' ' << a[j][cla] << ' ' << a[j][clb] << endl;
							h[i][cla][clb] += abs(a[j][cla] - a[j][clb]);
						}
		}
	}
	*/
}

void show_g();
void show_h();
void show_dp();

int main()
{
	init();
	//memset(dp, 0x7f, sizeof(dp));
	//for (int i = 0; i < (1 << n); i++)
		//dp[i][0][0] = 0;
	int ans = 0x7fffffff;
	for (int i = 0; i < (1 << n); i++)
		if (f(i))
		{
			memset(g, 0, sizeof(g));
			memset(h, 0, sizeof(h));
			memset(dp, 0x7f, sizeof(dp));
			dp[0][0] = 0;
			for (int col = 1; col <= m; col++)
			{
				int k = 0;
				while (!b[k])
					k++;
				for (int j = k + 1; j < n; j++)
					if (b[j])
					{
						g[col] += abs(a[j][col] - a[k][col]);
						k = j;
					}
			}
			for (int cla = 1; cla < m; cla++)
				for (int clb = cla + 1; clb <= m; clb++)
					for (int j = 0; j < n; j++)
						if (b[j])
						{
							h[cla][clb] += abs(a[j][cla] - a[j][clb]);
						}
			for (int j = 1; j <= m; j++)
				for (int k = 0; k < j; k++)
					for (int t = 1; t <= c; t++)
					{
						//dp[i][j][t] = min(dp[i][j][t], dp[i][k][t]);
						//dp[i][j][t] = min(dp[i][j][t], dp[i][k][t - 1] + g[i][j] + h[i][k][j]);
						dp[j][t] = min(dp[j][t], dp[k][t - 1] + g[j] + h[k][j]);
					}
			for (int j = 1; j <= m; j++)
				ans = min(ans, dp[j][c]);
			//show_g();
			//show_dp();
		}
	//show_g();
	//show_dp();
	/*
	for (int i = 0; i < (1 << n); i++)
		if (f(i))
		{
//cout << dp[i][m][c] << endl;
			for (int j = 1; j <= m; j++)
				ans = min(ans, dp[i][j][c]);
		}
	*/
	printf("%d\n", ans);
	return 0;
}

void show_dp()
{
	//for (int i = 0; i < (1 << n); i++)
		//if (f(i))
		//{
			for (int j = 0; j < n; j++)
				cout << b[j];
			cout << endl;
			for (int j = 0; j <= m; j++)
			{
				cout << j << "\t";
				for (int k = 0; k <= c; k++)
					//cout << dp[i][j][k] << "\t\t";
					//printf("%11d", dp[i][j][k]);
					printf("%11d", dp[j][k]);
				cout << endl;
			}
		//}
}
/*
void show_h()
{
	for (int i = 0; i < (1 << n); i++)
		if (f(i))
		{
			//cout << i << "\t\t";
			for (int j = 0; j < n; j++)
				cout << b[j];
			cout << endl;
			for (int l = 0; l < m; l++)
				for (int r = l + 1; r <= m; r++)
					cout << l << " " << r << "\t" << h[i][l][r] << endl;
			cout << endl;
		}
	
}
*/
void show_g()
{
	//for (int i = 0; i < (1 << n); i++)
		//if (f(i))
		//{
			//cout << i << "\t\t";
			for (int j = 0; j < n; j++)
				cout << b[j];
			cout << "\t\t";
			for (int j = 1; j <= m; j++)
				cout << g[j] << "\t";
			cout << endl;
		//}
}
