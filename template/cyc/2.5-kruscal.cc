#include "cyc.h"

const int maxn = 10000 + 10;
const int maxm = 100000 + 10;
int p[maxn], u[maxm], v[maxm], w[maxm], r[maxm];
int n, m;

bool cmp(int i, int j) { return w[i] < w[j]; }
int find(int x) { return p[x] == x ? x : p[x] = find(p[x]); }

int kruscal()
{
	int ans = 0;
	for (int i = 0; i < n; i++) 
		p[i] = i;
	for (int i = 0; i < m; i++) 
		r[i] = i;
	sort(r, r + m);
	for (int i = 0; i < m; i++)
	{
		int e = r[i], x = find(u[e]), y = find(v[e]);
		if (x != y)
		{
			ans += w[e];
			p[x] = y;
		}
	}
	return ans;
}
