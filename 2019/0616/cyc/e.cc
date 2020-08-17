#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

char s[1005], c[1005], p[30];
int cost[300], n, m;

int f()
{
	int ans = 0;
	for (int i = 0; i < m; i++)
		if (cost[p[i]] == 0x7f7f7f7f)
			return -1;
		else
			ans += cost[p[i]];
	return ans;
}

int main()
{
	int t;
	scanf("%d", &t);
	while (t--)
	{
		scanf("%d%d", &n, &m);
		scanf("%s%s%s", s, c, p);
		memset(cost, 0x7f, sizeof(cost));
		for (int i = 0; i < n; i++)
			cost[s[i]] = min(cost[s[i]], c[i] - '0');
		printf("%d\n", f());
	}
	return 0;
}
