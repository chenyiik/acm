#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int maxn = 200009;
int _a[maxn], *a = _a + maxn / 2, c[maxn];
char s[maxn];
int n;

int main()
{
	memset(_a, -1, sizeof(_a));
	scanf("%d%s", &n, s + 1);
	int tota = 0, totb = 0;
	for (int i = 1; i <= n; i++)
		if (s[i] == '1')
			c[i] = c[i - 1] + 1, tota++;
		else
			c[i] = c[i - 1] - 1, totb++;
	a[0] = 0;
	int ans = 0;
	for (int i = 1; i <= n; i++)
	{
		if (a[c[i]] != -1)
			ans = max(ans, i - a[c[i]]);
		else 
			a[c[i]] = i;
	}
	printf("%d %d\n", ans, min(tota, totb) * 2);
	return 0;
}
