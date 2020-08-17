#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct P { int l, r; };

int main()
{
	int n, m;
	scanf("%d%d", &n, &m);
	vector<P> v[2];
	while (m--)
	{
		int t, l, r;
		scanf("%d%d%d", &t, &l, &r);
		v[t].push_back({l, r});
	}
	const int maxn = 1005;
	static bool b[maxn];
	for (int i = 0; i < v[1].size(); i++)
	{
		for (int j = v[1][i].l; j < v[1][i].r; j++)
			b[j] = true;
	}
	static int a[maxn];
	for (int i = 0; i < v[0].size(); i++)
	{
		bool bb = false;
		for (int j = v[0][i].l; j < v[0][i].r; j++)
		{
			if (!b[j])
			{
				for (int k = j + 1; k <= n; k++)
					a[k]--;
				bb = true;
				break;
			}
		}
		if (!bb)
			return puts("NO"), 0;
	}
	puts("YES");
	for (int i = 1; i <= n; i++)
		printf("%d%c", a[i] + int(1e9), " \n"[i == n]);
	return 0;
}
