#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	static const int N = static_cast<int>(1e6) + 7;
	char s[N];
	while (~scanf("%s", s))
	{
		static int a[300];
		memset(a, 0, sizeof(a));
		for (char *p = s; *p != '\0'; ++p)
			a[*p]++;
		static char b[] = "abcdefghijklmnopqrstuvwxyz";
		sort(b, b + 26, [](char c0, char c1) { return a[c0] > a[c1]; });
		printf("%c%c", min(b[0], b[1]), max(b[0], b[1]));
	}
	return 0;
}
