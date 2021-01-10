#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int maxs = int(1e7), maxn = 1005;
char s[maxs];
int a[maxn];

int main()
{
	int _; scanf("%d", &_);
	while (_--)
	{
		int n, k; scanf("%d%d", &n, &k);
		for (int i = 0; i < n; i++)
		{
			scanf("%s", s);
			char *t = s;
			for (char *p = s; *p != '\0'; p++)
				if (*p == '/')
					t = p;
			sscanf(t + 1, "%d", &a[i]);
		}
		sort(a, a + n);
		for (int i = 0; i < k; i++)
			printf("%d%c", a[i], " \n"[i + 1 == k]);
	}
	return 0;
}
