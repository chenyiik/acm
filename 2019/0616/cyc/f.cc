#include <cstdio>
#include <cstring>
#include <cctype>
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int t;
	scanf("%d", &t);
	while (t--)
	{
		static char s[105];
		scanf("%s", s);
		int ans = 1;
		for (char *p = s; *p != 0; p++)
			if (isupper(*p))
				ans++;
		puts(ans <= 7 ? "YES" : "NO");
	}
	return 0;
}
