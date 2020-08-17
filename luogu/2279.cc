#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int maxN = 1005;
bool vis[maxN];
struct P { int fa, dep; }nd[maxN];
int p[maxN];
bool cmp(int a, int b)
{
	return nd[a].dep > nd[b].dep
		|| nd[a].dep == nd[b].dep && nd[a].fa < nd[b].fa;
}

int main()
{
	int n = 0;
	scanf("%d", &n);
	for (int i = 1; i < n; i++)
	{
		int x = 0;
		scanf("%d", &x);
		x--;
		nd[i] = {x, nd[x].dep + 1};
		p[i] = i;
	}
	sort(p, p + n, cmp);
	int ans = 0;
	for (int pi = 0; pi < n; pi++)
	{
		int i = p[pi];
		if (vis[i])
			continue;
		ans++;
		int p = i, p1 = nd[p].fa, p2 = nd[p1].fa, p3 = nd[p2].fa, p4 = nd[p3].fa;
		for (int j = 0; j < n; j++)
		{
			if (vis[j])
				continue;
			int q = j, q1 = nd[q].fa, q2 = nd[q1].fa;
			if (q == p2 || q1 == p2 || q2 == p2 || q == p3 || q1 == p3 || q == p4)
				vis[j] = true;
		}
	}
	printf("%d\n", ans);
	return 0;
}
