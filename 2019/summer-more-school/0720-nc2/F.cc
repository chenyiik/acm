#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

typedef long long LL;

const int maxn = 40;
LL a[maxn][maxn], r[maxn][maxn], q[maxn][maxn][maxn];
int mmp[maxn / 2], l[maxn];

int main()
{
	int n;
	scanf("%d", &n);
	int m = n * 2;
	LL tot = 0;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < m; j++)
		{
			scanf("%lld", &a[i][j]);
			if (i < n && j >= n)
				tot += a[i][j];
		}
		for (int j = m - 1; j > i; j--)
			r[i][j] = r[i][j + 1] + a[i][j];
	}
	for (int k = 0; k < m; k++)
		for (int i = 0; i < m; i++)
			for (int j = i; j < m; j++)
				if (k < i || k > j)
					for (int ii = i; ii <= j; ii++)
						q[k][i][j] += a[k][ii];
	int head = n;
	for (int i = 0; i < n; i++)
		mmp[i] = i, l[i + n] = i + n + 1;
	mmp[n] = m;
	LL ans = tot;
	while (true)
	{
		int p = n - 1;
		while (p >= 0 && mmp[p] == p + n)
			p--;
		if (p == -1)
			break;
		int k0 = mmp[p], k1 = mmp[p + 1], ll = k0 + 1, rr = ll + (n - p) - 1;
		for (int *i = mmp; i < mmp + p; i++)
			tot += r[*i][k1] + a[*i][k0] - q[*i][ll][rr];
		for (int *i = mmp + p, j = ll; i < mmp + n; i++, j++)
			l[*i] = head, head = *i, *i = j;
		bool b = false;
		for (int i = head, ii = -1; i < m; i = l[i])
		{
			if (b)
				tot -= r[i][k1] + a[i][k0];
			b |= i == k0;
			if (i < ll || i > rr)
				tot += q[i][ll][rr], ii = i;
			else if (ii == -1)
				head = l[i];
			else
				l[ii] = l[i];
		}
		ans = max(ans, tot);
	}
	printf("%lld\n", ans);
	return 0;
}
