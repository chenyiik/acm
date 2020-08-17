#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int maxn = int(1e6) + 10;
bool vis[maxn], mark[maxn];

int main()
{
	int n; scanf("%d", &n);
	vector<int> v, s;
	int tot = 0;
	int p = -1;
	for (int i = 0; i < n; i++)
	{
		int x; scanf("%d", &x);
		if (x > 0 && (vis[x] || mark[x]) || x < 0 && !vis[-x])
			return puts("-1"), 0;
		else if (x > 0)
			vis[x] = mark[x] = true, tot++, s.push_back(x);
		else
			vis[-x] = false, tot--;
		if (!tot)
		{
			v.push_back(i - p);
			for (int j : s)
				mark[j] = false;
			s.clear();
			p = i;
		}
	}
	if (tot)
		return puts("-1"), 0;
	printf("%lu\n", v.size());
	for (int i : v)
		printf("%d ", i);
	puts("");
	return 0;
}
