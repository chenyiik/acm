#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

struct P { int size, R; };

int main()
{
	int t;
	scanf("%d", &t);
	while (t--)
	{
		int n, m, q;
		scanf("%d%d%d", &n, &m, &q);
		static bool vis[100005];
		memset(vis, false, sizeof(vis));
		while (n--)
		{
			int l, r;
			scanf("%d%d", &l, &r);
			for (int i = l; i <= r; i++)
				vis[i] = true;
		}
		vector<P> v;
		for (int i = 1; i <= m; i++)
		{
			if (!vis[i])
			{
				int L = i;
				while (i + 1 <= m && !vis[i + 1])
					i++;
				int R = i, size = R - L + 1;
				while (!v.empty() && v[v.size() - 1].size <= size)
					v.pop_back();
				v.push_back({size, R});
			}
		}
		while (q--)
		{
			int k;
			scanf("%d", &k);
			bool b = false;
			for (int i = v.size() - 1; i >= 0; i--)
			{
				if (k <= v[i].size)
				{
					printf("%d %d\n", v[i].R - k + 1, v[i].R);
					b = true;
					break;
				}
			}
			if (!b)
				puts("-1 -1");
		}
	}
	return 0;
}
