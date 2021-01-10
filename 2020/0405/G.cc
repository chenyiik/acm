#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int maxn = 512;
bool a[maxn][maxn], z[maxn][maxn];
int n, m, dd[maxn], du[maxn];

bool check(int k)
{
	memset(z, 0, sizeof(z));
	memcpy(du, dd, sizeof(du));
	while (1)
	{
		bool flag = false;
		for (int i = 1; i < n; i++) for (int j = i + 1; j <= n; j++)
		{
			if (a[i][j] || z[i][j] || du[i] + du[j] < k)
				continue;
			z[i][j] = true;
			du[i]++, du[j]++;
			flag = true;
		}
		if (!flag)
			break;
	}
	bool ret = true;
	for (int i = 1; i < n; i++) for (int j = i + 1; j <= n; j++)
		ret &= a[i][j] || z[i][j];
	return ret;
}

int main()
{
	scanf("%d%d", &n, &m);
	while (m--)
	{
		int u, v; scanf("%d%d", &u, &v);
		a[u][v] = a[v][u] = true;
		dd[u]++, dd[v]++;
	}
	int l = 0, r = maxn * 2;
	while (l < r - 1)
	{
		int mid = (l + r) / 2;
		(check(mid) ? l : r) = mid;
	}
	printf("%d\n", l);
	return 0;
}
