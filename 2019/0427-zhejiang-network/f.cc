#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int t = 0;
	scanf("%d", &t);
	while (t--)
	{
		static char s[105];
		scanf("%s", s);
		for (char *p = s; *p != 0; p++)
		{
			if (*p == 'a' || *p == 'e' || *p == 'i' || *p == 'y' || *p == 'o' || *p == 'u')
			{
				if (p == s)
					putchar(*p);
			}
			else
				putchar(*p);
		}
		puts("");
	}
	return 0;
}
