#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int maxn = int(1e5) + 5;
char s[maxn];

int main()
{
	scanf("%s", s);
	bool cnt = true;
	for (char *p = s; *p; p++)
		if (*p == '1')
			cnt = !cnt;
	puts(cnt ? "YES" : "NO");
	return 0;
}
