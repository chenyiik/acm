#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

char s[105];
int c[300];

int main()
{
	int n = 0;
	fgets(s, 100, stdin);
	sscanf(s, "%d", &n);
	while (n--)
	{
		fgets(s, 100, stdin);
		memset(c, 0, sizeof(c));
		for (char *p = s; *p != '\0'; ++p)
			c[*p]++;
		printf("a:%d\ne:%d\ni:%d\no:%d\nu:%d\n", c['a'], c['e'], c['i'], c['o'], c['u']);
		if (n)
			puts("");
	}
	return 0;
}
