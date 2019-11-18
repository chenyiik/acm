#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int maxn = 1005;
int c[maxn], p[maxn], a[maxn];


int main()
{
	int n, m, d; scanf("%d%d%d", &n, &m, &d);
	for (int i = 1; i <= m; i++)
		scanf("%d", &c[i]);
	for (int i = m, t = p[m + 1] = n + 1; i > 0; i--)
		p[i] = t -= c[i];
	int pos = 0;
	for (int i = 1; i <= m; i++)
	{
		int nxt = min(p[i], pos + d);
		for (int j = pos + 1; j < nxt; j++)
			a[j] = 0;
		for (int j = nxt; j < nxt + c[i]; j++)
			a[j] = i;
		pos = nxt + c[i] - 1;
	}
	if (pos + d <= n)
		return puts("NO"), 0;
	puts("YES");
	for (int i = 1; i <= n; i++)
		printf("%d%c", a[i], " \n"[i == n]);
	return 0;
}
