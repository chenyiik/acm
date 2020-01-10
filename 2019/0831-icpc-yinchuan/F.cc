#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

typedef long long LL;

const LL oo = 0x3f3f3f3f3f3f3f3fLL;
int r[205], s[205], d[20005];
LL a[205][205];
struct P { int u, v, w; LL ans; } que[20005];

int main()
{
	int __; scanf("%d", &__);
	for (int _ = 1; _ <= __; _++)
	{
		int n, q; scanf("%d %d", &n, &q);
		for (int i = 1; i <= n; i++)
		{
			scanf("%d", &r[i]);
			s[i] = i;
		}
		sort(s + 1, s + 1 + n, [](int a, int b) { return r[a] < r[b]; });
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				scanf("%lld", &a[i][j]);
		for (int i = 1; i <= q; i++)
		{
			P &e = que[i];
			scanf("%d%d%d", &e.u, &e.v, &e.w);
			d[i] = i;
		}
		sort(d + 1, d + 1 + q, [](int a, int b) { return que[a].w < que[b].w; });
		int si = 1;
		for (int di = 1; di <= q; di++)
		{
			while (si <= n && r[s[si]] <= que[d[di]].w)
			{
				for (int i = 1; i <= n; i++)
					for (int j = 1; j <= n; j++)
						a[i][j] = min(a[i][j], a[i][s[si]] + a[s[si]][j]);
				si++;
			}
			que[d[di]].ans = a[que[d[di]].u][que[d[di]].v];
		}
		printf("Case #%d:\n", _);
		for (int i = 1; i <= q; i++)
			printf("%lld\n", que[i].ans);
	}
	return 0;
}
