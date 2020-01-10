#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int maxn = int(2e6) + 10;
char s[maxn];
const char *c = "harbin";
bool a[10][10];
bool vis[10];

bool dfs(int n)
{
	if (n == 6)
		return true;
	for (int i = 0; i < 6; i++) if (a[n][i] && !vis[i])
	{
		vis[i] = true;
		if (dfs(n + 1))
			return true;
		vis[i] = false;
	}
	return false;
}

int main()
{
	int t; scanf("%d", &t);
	while (t--)
	{
		memset(a, 0, sizeof(a));
		for (int i = 0; i < 6; i++)
		{
			scanf("%s", s);
			for (char *p = s; *p; p++)
				for (int j = 0; j < 6; j++)
					if (*p == c[j])
						a[i][j] = true;
		}
		memset(vis, 0, sizeof(vis));
		puts(dfs(0) ? "Yes" : "No");
	}
	return 0;
}
