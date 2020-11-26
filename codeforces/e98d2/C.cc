#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int maxn = int(2e5) + 5;
char s[maxn];

int main()
{
	int T; scanf("%d", &T);
	while (T--)
	{
		scanf("%s", s);
		int d0 = 0, d1 = 0, ans = 0;
		for (char *p = s; *p != '\0'; p++)
		{
			if (*p == '(') d0++;
			if (*p == '[') d1++;
			if (*p == ')' && d0) d0--, ans++;
			if (*p == ']' && d1) d1--, ans++;
		}
		printf("%d\n", ans);
	}
	return 0;
}
