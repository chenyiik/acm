#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int t = 0;
	scanf("%d", &t);
	while (t--)
	{
		int a1, a2, a3, b1, b2, b3;
		scanf("%d%d%d%d%d%d", &a1, &a2, &a3, &b1, &b2, &b3);
		int c1 = a1 + b1, c2 = a2 + b2, c3 = a3 + b3;
		if (c3 > 59)
		{
			c3 -= 60;
			c2++;
		}
		if (c2 > 59)
		{
			c2 -= 60;
			c1++;
		}
		printf("%d %d %d\n", c1, c2, c3);
	}
	return 0;
}
