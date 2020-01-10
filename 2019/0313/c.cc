#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

typedef long long LL;

LL a[110][110], f[110][110];
int pre[110][110], n, m;

int main()
{
	int t = 0;
	scanf("%d", &t);
	for (int Case = 1; Case <= t; Case++)
	{
		printf("Case %d\n", Case);
		scanf("%d%d", &n, &m);
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= m; j++)
				scanf("%lld", &a[i][j]);
		memset(f, 0x3f, sizeof(f));
		for (int i = 1; i <= m; i++)
			f[n + 1][i] = 0LL;
		for (int i = n; i > 0; i--)
			for (int j = 1; j <= m; j++)
				for (int k = -1; k <= 1; k++)
					if (f[i][j] >= f[i + 1][j + k] + a[i][j])
					{
						f[i][j] = f[i + 1][j + k] + a[i][j];
						pre[i][j] = k;
					}
		int num = 1;
		LL sum = f[1][1];
		for (int i = 2; i <= m; i++)
			if (sum >= f[1][i])
			{
				num = i;
				sum = f[1][i];
			}
		for (int i = 1, j = num; i <= n; j = j + pre[i][j], i++)
			printf("%d%c", j, (i == n ? '\n' : ' '));
		/*
		cout << num << endl;
		for (int i = 1; i <= n; i++)
		{
			for (int j = 0; j <= m + 1; j++)
				cout << pre[i][j] << ' ';
			cout << endl;
		}
		for (int i = 1; i <= n; i++)
		{
			for (int j = 0; j <= m + 1; j++)
				cout << f[i][j] << ' ';
			cout << endl;
		}
		*/
	}
	return 0;
}
