#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

const int maxn = 2005;
int a[maxn], t[maxn][maxn];

int main()
{
	int _; scanf("%d", &_);
	while (_--)
	{
		int n; scanf("%d", &n);
		int m = 0;
		unordered_map<int, int> M;
		for (int i = 1; i <= n; i++)
		{
			scanf("%d", &a[i]);
			auto it = M.find(a[i]);
			if (it == M.end())
				M[a[i]] = m++;
		}
		for (auto i : M)
		{
			t[i.second][n + 1] = 0;
			for (int j = n; j > 0; j--)
				t[i.second][j] = t[i.second][j + 1] + (a[j] == i.first);
		}
		long long ans = 0;
		for (int i = 1; i < n; i++)
			for (int j = i + 1; j <= n; j++)
			{
				int k = a[j] + a[j] - a[i];
				auto it = M.find(k);
				if (it != M.end())
					ans += t[it->second][j + 1];
				//cout << a[i] << ' ' << a[j] << ' ' << k << ' ' << ans << endl;
			}
		printf("%lld\n", ans);
	}
	return 0;
}
