#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int maxn = int(5e4);
const int maxm = maxn;
//char s[maxn][maxm];
int totR[maxn], totC[maxm];
char *s[maxn];


int main()
{
	int t = 0;
	scanf("%d", &t);
	while (t--)
	{
		int n, m;
		scanf("%d%d", &n, &m);
		for (int j = 0; j < m; j++)
			totC[j] = 0;
		for (int i = 0; i < n; i++)
		{
			s[i] = new char[m + 1];
			totR[i] = 0;
			scanf("%s", s[i]);
			for (int j = 0; j < m; j++)
				if (s[i][j] == '*')
					totR[i]++, totC[j]++;
		}
		int ans = 0x7fffffff;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
				ans = min(ans, (n + m - 1) - (totR[i] + totC[j] - (s[i][j] == '*' ? 1 : 0)));
			delete s[i];
		}
		printf("%d\n", ans);
	}
	return 0;
}
