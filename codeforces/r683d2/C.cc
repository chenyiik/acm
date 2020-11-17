#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>

using namespace std;

const int maxn = int(2e5) + 5;
pair<int, int> w[maxn];

bool cmp(pair<int, int> a, pair<int, int> b) { return a.second > b.second; }

int main()
{
	int t; scanf("%d", &t);
	while (t--)
	{
		int n; long long m; scanf("%d%lld", &n, &m);
		long long m2 = m / 2 + m % 2;
		for (int i = 0; i < n; i++)
		{
			w[i].first = i + 1;
			scanf("%d", &w[i].second);
		}
		sort(w, w + n, cmp);
		vector<pair<int, int>> v;
		long long count = 0;
		for (int i = 0; i < n; i++)
		{
			if (count + w[i].second <= m)
			{
				count += w[i].second;
				v.push_back(w[i]);
			}
			if (count >= m2)
				break;
		}
		if (count < m2)
		{
			puts("-1");
			continue;
		}
		sort(v.begin(), v.end());
		printf("%d\n", v.size());
		for (int i = 0; i < v.size(); i++)
			printf("%d%c", v[i].first, " \n"[i + 1 == n]);
	}
	return 0;
}
