#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int maxn = 1005;
char s[maxn];

int main()
{
	int t; scanf("%d", &t);
	while (t--)
	{
		int n, c0, c1, h; scanf("%d%d%d%d%s", &n, &c0, &c1, &h, s);
		int count0 = 0, count1 = 0;
		for (int i = 0; i < n; i++)
 		{
			if (s[i] == '0') count0++;
			else count1++;
		}
		if (c0 + h < c1)
			printf("%d\n", count0 * c0 + count1 * (c0 + h));
		else if (c1 + h < c0)
			printf("%d\n", count0 * (c1 + h) + count1 * c1);
		else
			printf("%d\n", count0 * c0 + count1 * c1);
	}
	return 0;
}
