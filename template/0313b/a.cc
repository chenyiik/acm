#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

bool b[1005];

int dfs(const char s[], int L, int R, int k)
{
	//cout << L << ' ' << R << ' ' << k << endl;
	if (k == 0 || L == R)
		return 0;
	int p = L;
	for (int i = L + 1; i < R; i++)
	{
		if (s[i] < s[p])
			p = i;
	}
	b[p] = true;
	int r = dfs(s, p + 1, R, k - 1);
	int l = r + 1 == k ? 0 : dfs(s, L, p, k - 1 - r);
	return l + r + 1;
}

int main()
{
	static char s[1005];
	int m;
	while (~scanf("%s%d", s, &m))
	{
		int n = strlen(s);
		m = n - m;
		memset(b, false, sizeof(b));
		dfs(s, 0, n, m);
		bool bb = false;
		for (int i = 0; i < n; i++)
		{
			if (!b[i])
				continue;
			if (s[i] == '0' && !bb)
				continue;
			bb = true;
			putchar(s[i]);
		}
		puts(bb ? "" : "0");
	}
	return 0;
}
