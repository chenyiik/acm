#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int maxn = int(1e5) + 5;
char s[maxn];

int main()
{
	int _; scanf("%d", &_);
	while (_--)
	{
		int a, b; scanf("%d%d%s", &a, &b, s + 1);
		s[0] = '0';
		int ans = 0, tot = -1;
		for (char *p = s + 1; *p != '\0'; p++)
		{
			if (p[-1] == '0' && p[0] == '0')
			{
				if (tot != -1)
					tot++;
			}
			if (p[-1] == '0' && p[0] == '1')
			{
				if (tot != -1)
					ans += min(tot * b, a);
				else
					ans += a;
			}
			if (p[-1] == '1' && p[0] == '0')
			{
				tot = 1;
			}
			if (p[-1] == '1' && p[0] == '1')
			{
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
