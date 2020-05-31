#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int maxn = int(1e5) + 5;
char s[maxn];
int a[maxn], n;

int main()
{
	scanf("%s", s);
	for (char *p = s; *p; p++)
		if (*p == 'a' || *p == 'e' || *p == 'i' || *p == 'o' || *p == 'u')
			a[n++] = p - s;
	if (!n) puts("1");
	else if (a[0]) puts("0");
	else if (n == 1) printf("%d\n", strlen(s));
	else 
	{
		int l = 0, r = n - 1, d = 0;
		while (l + 1 < r) !d ? (l++, d++) : (r--, d--);
		printf("%d\n", a[r] - a[l]);
	}
	return 0;
}
