#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

struct P 
{ 
	int pos, val; 
	bool operator<(P o) const 
	{ 
		return pos < o.pos; 
	} 
} u[100007];

int g[100007], d[100007], a[100007];

int main()
{
	int n = 0;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &u[i].pos);
		u[i].val = i;
	}
	sort(u + 1, u + n + 1);

	for (int i = 0; i < n; i++)
	{
		int x = 0;
		scanf("%d", &x);
		a[i] = u[x].val;
	}


	for (int i = 1; i <= n; i++)
		g[i] = 0x7fffffff;
	for (int i = 0; i < n; i++)
	{
		int k = lower_bound(g + 1, g + n + 1, a[i]) - g;
		d[i] = k;
		g[k] = a[i];
	}
	int ans = 0;
	for (int i = 0; i < n; i++)
		ans = max(ans, d[i]);
	printf("%d\n", ans);
	return 0;
}
