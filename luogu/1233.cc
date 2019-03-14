#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

struct P
{
	int x, y;
	bool operator<(const P &o) const { return y > o.y || y == o.y && x > o.x; }
} a[5005];

bool vis[5005];
int n;

void dfs(int l, int r)
{
	for (int i = 0; i < n; i++)
	{
		if (vis[i])
			continue;
		if (l >= a[i].x && r >= a[i].y)
		{
			vis[i] = true;
			dfs(a[i].x, a[i].y);
			return;
		}
	}
}

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d%d", &a[i].x, &a[i].y);
	sort(a, a + n);
	int ans = 0;
	for (int i = 0; i < n; i++)
	{
		if (vis[i])
			continue;
		ans++;
		vis[i] = true;
		dfs(a[i].x, a[i].y);
	}
	printf("%d\n", ans);
	return 0;
}
