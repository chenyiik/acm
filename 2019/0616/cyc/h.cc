#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

char s[1005];

bool f()
{
	for (char *p = s + 1; *p != 0; p++)
		if (p[0] - p[-1] != 1 && !(p[0] == 'a' && p[-1] == 'z'))
			return false;
	return true;
}

int main()
{
	int t;
	scanf("%d", &t);
	while (t--)
	{
		scanf("%s", s);
		puts(f() ? "YES" : "NO");
	}
	return 0;
}
