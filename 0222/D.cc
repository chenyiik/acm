#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int maxn = int(1e6) + 5;
char s[maxn], t[maxn];

bool check()
{
	char *j = t;
	for (char *i = s; *i != '\0'; i++)
	{
		if (*j == *i)
			j++;
	}
	return *j == '\0';
}

int main()
{
	scanf("%s%s", s, t);
	puts(check() ? "YES" : "NO");
	return 0;
}
