#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int maxn = int(1e7) + 10;
char s[maxn], t[maxn];
long long f[maxn];

void getFail(char *P, long long *f, int m)
{
	f[0] = f[1] = 0;
	for (int i = 1; i < m; i++)
	{
		long long j = f[i];
		while (j && P[i] != P[j])
			j = f[j];
		f[i + 1] = P[i] == P[j] ? j + 1 : 0;
	}
}

int main()
{
	int a, b; scanf("%d%d%s", &a, &b, s);
	int l = strlen(s), n = 0;
	for (int i = l - 1; i >= 0 && s[i] != '.'; i--)
		t[n++] = s[i];
	getFail(t, f, n);
	long long ans = 0x8000000000000000LL;
	for (long long i = 1; i <= n; i++)
		//cout << f[i] << ' ' << i << endl,
		ans = max(ans, a * i - b * (i - f[i]));
	printf("%lld\n", ans);
	return 0;
}
