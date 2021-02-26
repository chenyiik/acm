#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

const int maxn = 505;

struct P
{
	int x, y, c; 
	bool operator<(const P &o) const { return c < o.c; }
} a[maxn * maxn];

char s[maxn][maxn];
bool vis[maxn][maxn];
priority_queue<P> Q;
int ans = 0;

void ins(int x, int y, int c)
{
	Q.push({x, y, c});
	vis[x][y] = true;
	ans++;
}

void addQ(int &kk)
{
		int &x = a[kk].x, &y = a[kk].y;
		if (s[x][y] == '.' && !vis[x][y])
			ins(x, y, a[kk].c);
		kk++;
}

int main()
{
	int n, m, k; scanf("%d%d%d", &n, &m, &k);
	for (int i = 0; i < n; i++)
		scanf("%s", s[i]);
	for (int i = 0; i < k; i++)
	{
		scanf("%d%d%d", &a[i].x, &a[i].y, &a[i].c);
		a[i].x--, a[i].y--;
	}
	sort(a, a + k, [](const P &a, const P &b){ return b < a; });
	int kk = 0;
	while (kk < k && a[kk].c == a[0].c)
		addQ(kk);
	while (!Q.empty())
	{
		P t = Q.top();
		Q.pop();
		if (t.c == 0)
			continue;
		const int mv[4][2] = {{-1, 0}, {0, -1}, {0, 1}, {1, 0}};
		for (int i = 0; i < 4; i++)
		{
			int x = t.x + mv[i][0], y = t.y + mv[i][1];
			if (x < 0 || x >= n || y < 0 || y >= m || s[x][y] == 'X' || vis[x][y])
				continue;
			ins(x, y, t.c - 1);
		}
		while (kk < k && (Q.empty() || a[kk].c == Q.top().c))
			addQ(kk);
	}
	printf("%d\n", ans);
	return 0;
}
