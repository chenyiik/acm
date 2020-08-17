#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

struct P { int ti, li, hi; };

struct R
{
	int t, f, h;
	bool operator<(const R &o) const
	{
		return t < o.t || t == o.t && h > o.h || t == o.t && h == o.h && f > o.f;
	}
} a[105];

int dp[1005][105];

void show(int d, int ti)
{
	for (int i = 0; i <= ti; i++)
	{
		printf("%d\t", a[i].t);
		for (int j = 0; j < d; j++)
			printf("%d ", dp[a[i].t][j]);
		puts("");
	}
}

int main()
{
	int d = 0, g = 0;
	scanf("%d%d", &d, &g);
	for (int i = 0; i < g; i++)
		scanf("%d%d%d", &a[i].t, &a[i].f, &a[i].h);
	sort(a, a + g);
	//puts("");
	//for (int i = 0; i < g; i++)
		//printf("%d %d %d\n", a[i].t, a[i].f, a[i].h);
	int pre_t = 0;
	memset(dp, 0xff, sizeof(dp));
	dp[0][0] = 10;
	for (int i = 0; i < g; i++)
	{
		int dlt = a[i].t - pre_t;
		for (int j = d - 1; j >= 0; j--)
		{
			if (dp[pre_t][j] < dlt)
				continue;
			if (j + a[i].h >= d)
				return printf("%d\n", a[i].t), 0;
			dp[a[i].t][j + a[i].h] = max(dp[a[i].t][j + a[i].h], dp[pre_t][j] - dlt);
			dp[a[i].t][j] = max(dp[a[i].t][j], dp[pre_t][j] - dlt + a[i].f);
		}
		//printf("%d\t", a[i].t);
		//for (int j = 0; j < d; j++)
			//printf("%d ", dp[a[i].t][j]);
		//puts("");
		pre_t = a[i].t;
	}
	int max_t = 0;
	for (int i = 0; i <= 1000; i++)
	{
		for (int j = 0; j < d; j++)
		{
			if (dp[i][j] != -1)
				max_t = max(max_t, dp[i][j] + i);
		}
	}
	//puts("aAa");
	return printf("%d\n", max_t), 0;
}
