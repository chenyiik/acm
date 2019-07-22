#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

typedef long long LL;

const int maxn = int(3e5) + 5, maxm = int(3e4) + 5, maxv = 13;
LL a[maxn], L[maxv][maxn], R[maxv][maxn], P[maxv][maxn], ans = 0, k;

void init(const LL *a, int n, int u, int v)
{
	//cout << u << ' ' << v << endl;
	if (n < 1)
		return;
	LL tot = -k;
	P[u][v] = -k;
	for (int i = 0; i < n; i++)
	{
		ans = max(ans, tot += a[i]);
		if (tot < 0)
			tot = -k;
		P[u][v] += a[i];
		//cout << P[1][0] << endl;
	}
	tot = -k;
	for (int i = 0; i < n; i++)
		L[u][v] = max(L[u][v], tot += a[i]);
	tot = -k;
	for (int i = n - 1; i >= 0; i--)
		R[u][v] = max(R[u][v], tot += a[i]);
}

int main()
{
	int n, m;
	scanf("%d%d%lld", &n, &m, &k);
	for (int i = 0; i < n; i++)
		scanf("%lld", &a[i]);
	for (int u = 1; u <= m; u++)
	{
		init(a, u, u, 0);
		int bl = (n - u) / m;
		for (int d = 1; d <= bl; d++)
			init(a + u + (d - 1) * m, m, u, d);
		if (u + bl * m < n)
			init(a + u + bl * m, m, u, bl);
	}
	for (int u = 1; u <= m; u++)
	{
		int bl = (n - u) / m;
		ans = max(ans, L[u][0]);
		LL tot = R[u][0];
		for (int i = 1; i <= bl + 1; i++)
		{
			ans = max(ans, tot + L[u][i]);
			tot += P[u][i];
			if (tot < 0)
				tot = R[u][i];
		}
		ans = max(ans, tot);
		//for (int i = 0; i <= bl + 1; i++)
			//printf("%d %d %lld %lld %lld\n", u, i, P[u][i], L[u][i], R[u][i]);

	}
	printf("%lld\n", ans);
	return 0;
}
