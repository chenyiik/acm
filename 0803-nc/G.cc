#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int maxn = int(1e5) + 5;
char s[maxn][15], ans[15];

bool is_friday(char s[]);
bool _try(int n)
{
}

int main()
{
	int tn;
	scanf("%d", &tn);
	for (int cas = 1; cas <= tn; cas++)
	{
		int n;
		scanf("%d", &n);
		for (int i = 0; i < n; i++)
			scanf("%s", s[i]);
		printf("Case #%d: %s\n", cas, _try(n) ? ans : "Impossible");
	}
	return 0;
}

bool is_friday(char s[])
{
	int c, y, m, d;
	sscanf(s, "%2d%2d/%d/%d", &c, &y, &m, &d);
	int w = (y + y / 4 + c / 4 - 2 * c + (26 * (m + 1)) / 10 + d - 1) % 7;
	return w == 5;
}
