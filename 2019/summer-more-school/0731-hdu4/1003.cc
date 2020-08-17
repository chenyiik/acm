#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef long long LL;

vector<int> v[int(1e5) + 5];

int main()
{
	int t;
	scanf("%d", &t);
	while (t--)
	{
		LL n, k;
		scanf("%lld%lld", &n, &k);
		if (n * (n + 1) / 2 % k != 0)
		{
			puts("no");
			continue;
		}
		puts("yes");
		for (int i = 0; i < k; i++)
			v[i].clear();
		int minv = 1;
		if (k > 1 && n / k % 2 == 1)
		{
			int j = 1, s = k * 2 + 1 - k / 2;
			for (int i = 0; i < k; i += 2, j++)
				v[i].push_back(j), v[i].push_back(s + i - j);
			for (int i = 1; i < k; i += 2, j++)
				v[i].push_back(j), v[i].push_back(s + i - j);
			minv = 2 * k + 1;
		}
		for (int i = n, j = 0, d = 1; i >= minv; i--)
		{
			v[j].push_back(i);
			j += d;
			if (j < 0)
				j = 0, d = 1;
			if (j >= k)
				j = k - 1, d = -1;
		}
		for (int i = 0; i < k; i++)
			for (int j = 0; j < v[i].size(); j++)
				printf("%d%c", v[i][j], " \n"[j == v[i].size() - 1]);
	}
	return 0;
}
