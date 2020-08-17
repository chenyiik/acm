#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int maxn = int(1e6) + 10;

char s[maxn];
int f[maxn], g[maxn];

void getFail(char *P, int *f)
{
	int m = strlen(P);
	f[0] = f[1] = 0;
	for (int i = 1; i < m; i++)
	{
		int j = f[i];
		while (j && P[i] != P[j])
			j = f[j];
		f[i + 1] = P[i] == P[j] ? j + 1 : 0;
	}
}

int main()
{
	int t;
	scanf("%d", &t);
	while (t--)
	{
		scanf("%s", s);
		getFail(s, f);
		int m = strlen(s);
		long long ans = m - 1;
		g[0] = -1;
		for (int i = 1; i < m; i++)
			ans += g[i] = g[f[i]] + 1;
		printf("%lld\n", ans);
	}
	return 0;
}
