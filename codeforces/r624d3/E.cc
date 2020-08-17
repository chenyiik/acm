#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int maxn = 5005;
int ans[maxn];
vector<int> v[maxn];

int main()
{
	int t; scanf("%d", &t);
	while (t--)
	{
		int n, d; scanf("%d%d", &n, &d);
		int mi = 0, ma = n * (n - 1) / 2;
		for (int i = 0, p = 1, s = n; s > 0; i++, p *= 2)
			mi += i * min(p, s), s -= p;
		if (d < mi || d > ma)
		{
			puts("NO");
			continue;
		}
		puts("YES");
		for (int i = 1; i < n; i++)
			v[i] = {i};
		int can = 2;
		for (int i = n, need = ma - d; i >= 2; i--)
		{
			if (need <= 0)
				ans[i] = i - 1;
			else
			{
				int des = max(can, i - need);
				ans[i] = v[des - 1][v[des].size() / 2];
				v[des].push_back(i);
				if (v[des].size() == 1 << (des - 1))
					can++;
				need -= i - des;
			}
		}
		for (int i = 2; i <= n; i++)
			printf("%d%c", ans[i], " \n"[i == n]);
	}
	return 0;
}
