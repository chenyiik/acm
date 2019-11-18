#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
 
using namespace std;
 
int main()
{
	int t; scanf("%d", &t);
	while (t--)
	{
		int n, a, b, c; static char s[105];
		scanf("%d%d%d%d%s", &n, &a, &b, &c, s);
		int ans = 0; static char t[105];
		memset(t, 0, sizeof(t));
		for (int i = 0; i < n; i++)
		{
			if (s[i] == 'R')
			{
				if (b > 0)
					t[i] = 'P', b--, ans++;
			}
			else if (s[i] == 'P')
			{
				if (c > 0)
					t[i] = 'S', c--, ans++;
			}
			else if (s[i] == 'S')
			{
				if (a > 0)
					t[i] = 'R', a--, ans++;
			}
		}
		if (ans * 2 < n)
		{
			puts("NO");
			continue;
		}
		for (int i = 0; i < n; i++) if (!t[i])
		{
			if (a > 0)
				t[i] = 'R', a--;
			else if (b > 0)
				t[i] = 'P', b--;
			else if (c > 0)
				t[i] = 'S', c--;
		}
		printf("YES\n%s\n", t);
	}
	return 0;
}
