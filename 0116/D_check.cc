#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <map>
#include <utility>

using namespace std;

const int maxn = int(1e5) + 10;
map<int, int> M[maxn];
int n, k;
pair<int, int> a[maxn];

int main()
{
	freopen("gen.in", "r", stdin);
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
	{
		int m; scanf("%d", &m);
		while (m--)
		{
			int x; cin >> x;
			auto it = M[i].find(x);
			if (it == M[i].end())
				M[i][x] = 1;
			else
				it->second++;
		}
	}
	freopen("gen.ans", "r", stdin);
	int p; cin >> p;
	freopen("gen.out", "r", stdin);
	int m; cin >> m;
	if (p != m)
		return 1;
	for (int i = 0; i < m; i++)
		cin >> a[i].first >> a[i].second;
	for (int i = 0; i < m - 1; i++)
	{
		if (!(a[i].second < a[i + 1].second))
			return 2;
		auto it = M[a[i].first].find(a[i].second);
		if (it == M[a[i].first].end() || it->second == 0)
			return 3;
		it->second--;
		int l = a[i].first == n ? 1 : a[i].first + 1, r = l + k;
		if (r <= n)
		{
			if (!(l <= a[i + 1].first && a[i + 1].first <= r))
				return 4;
		}
		else
		{
			if (!(l <= a[i + 1].first || a[i + 1].first <= r - n))
				return 5;
		}
	}
	return 0;
}
