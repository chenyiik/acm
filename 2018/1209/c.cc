#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int d[10] = {1, 0, 0, 0, 1, 0, 1, 0, 2, 1};
	int t = 0;
	scanf("%d", &t);
	while (t--)
	{
		int x = 0, k = 0;
		scanf("%d%d", &x, &k);
		while (k && x > 1)
		{
			char s[20];
			sprintf(s, "%d", x);
			x = 0;
			for (char *p = s; *p != '\0'; p++)
				x += d[*p - '0'];
			k--;
		}
		if (k % 2 == 1)
			x ^= 1;
		printf("%d\n", x);
	}
	return 0;
}
