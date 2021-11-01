#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int maxn = int(5e5) + 7, maxm = int(1e6) + 7;
struct P { int u, v, w; };

int p[maxn];
P e[maxm];

int find(int x) { return p[x] == x ? x : p[x] = find(p[x]); }
bool check(int u, int v) { return find(u) == find(v); }
void merge(int u, int v) { p[find(u)] = find(v); }

int main()
{
	int _; scanf("%d", &_);
	while (_--)
	{
		int n, m; scanf("%d%d", &n, &m);
		for (int i = 1; i <= n; i++)
			p[i] = i;
		int ans = 0, len = 0;
		for (int i = 0; i < m; i++)
		{
			int u, v, w; scanf("%d%d%d", &u, &v, &w);
			if (w == 0)
			{
				if (!check(u, v))
					merge(u, v);
				ans++;
			}
			else
				e[len++] = {u, v, w};
		}
		for (int i = 0; i < len; i++)
		{
			if (!check(e[i].u, e[i].v))
			{
				merge(e[i].u, e[i].v);
				ans++;
			}
		}
		//for (int i = 1; i <= n; i++)
		//	cout << p[i] << ' ';
		//cout << endl;
		printf("%d\n", ans);
	}
	return 0;
}
