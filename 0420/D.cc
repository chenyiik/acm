#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <utility>
#include <map>

using namespace std;

const int maxn = int(1e5) + 10;
int a[maxn];

int main()
{
	int T; scanf("%d", &T);
	while (T--)
	{
		int n; scanf("%d", &n);
		for (int i = 0; i < n; i++) scanf("%d", &a[i]);
		int ans = 1, l = 0;
		map<int, int> M;
		M[a[0]] = 1;
		for (int r = 1; r < n; r++)
		{
			if (M.find(a[r]) == M.end()) M[a[r]] = 1;
			else M[a[r]]++;
			while (true)
			{
				map<int, int>::iterator it = M.find(a[r]);
				if (it != M.begin())
				{
					pair<int, int> p = *(--it);
					if (a[r] % p.first != 0)
					{
						while (p.second > 0)
						{
							if (--M[a[l]] == 0) M.erase(M.find(a[l]));
							if (a[l] == p.first) --p.second;
							l++;
						}
						continue;
					}
					++it;
				}
				if (++it != M.end())
				{
					pair<int, int> p = *it;
					if (p.first % a[r] != 0)
					{
						while (p.second > 0)
						{
							if (--M[a[l]] == 0) M.erase(M.find(a[l]));
							if (a[l] == p.first) --p.second;
							l++;
						}
						continue;
					}
				}
				break;
			}
			ans = max(ans, r - l + 1);
		}
		printf("%d\n", ans);
	}
	return 0;
}
