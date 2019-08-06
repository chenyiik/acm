#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int mod = 998244353;
const int maxn = 101;

struct P { int l, x; };
vector<P> v[maxn];
int dp[2][maxn][maxn][maxn];

void add(int &x, int y) { if ((x += y) >= mod) x -= mod; }

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		int n, m;
		scanf("%d%d", &n, &m);
		for (auto &i : v)
			i.clear();
		while (m--)
		{
			int l, r, x;
			scanf("%d%d%d", &l, &r, &x);
			v[r].push_back({l, x});
		}
		dp[0][0][0][0] = 1;
		for (int i = 1, p = 1; i <= n; i++, p ^= 1)
		{
			for (int j = 0; j <= i; j++)
				for (int k = 0; k <= j; k++)
					for (int t = 0; t <= k; t++)
						dp[p][j][k][t] = 0;
			for (int j = 0; j < i; j++)
				for (int k = 0; k <= j; k++)
					for (int t = 0; t <= k; t++)
					{
						int x = dp[p ^ 1][j][k][t];
						add(dp[p][j][k][t], x);
						add(dp[p][i - 1][k][t], x);
						add(dp[p][i - 1][j][t], x);
						add(dp[p][i - 1][j][k], x);
					}
			for (int j = 0; j < i; j++)
				for (int k = 0; k <= j; k++)
					for (int t = 0; t <= k; t++)
						for (const P &q : v[i])
							if (1 + (j >= q.l) + (k >= q.l) + (t >= q.l)
									!= q.x)
								dp[p][j][k][t] = 0;
		}
		int ans = 0, i = n % 2;
		for (int j = 0; j < n; j++)
			for (int k = 0; k <= j; k++)
				for (int t = 0; t <= k; t++)
					add(ans, dp[i][j][k][t]);
		printf("%d\n", ans);
	}
	return 0;
}
