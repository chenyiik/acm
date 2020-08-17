#include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int t = 0;
	scanf("%d", &t);
	while (t--)
	{
		int n = 0, x = 0, y = 0, d = 0;
		scanf("%d%d%d%d", &n, &x, &y, &d);
		if ((x - y) % d == 0)
			printf("%d\n", abs(x - y) / d);
		else if ((y - 1) % d == 0 && (n - y) % d == 0)
		{
			int a = (x - 1) / d + ((x - 1) % d > 0) + (y - 1) / d;
			int b = (n - x) / d + ((n - x) % d > 0) + (n - y) / d;
			printf("%d\n", min(a, b));
		}
		else if ((y - 1) % d == 0)
			printf("%d\n", (x - 1) / d + ((x - 1) % d != 0) + (y - 1) / d);
		else if ((n - y) % d == 0)
			printf("%d\n", (n - x) / d + ((n - x) % d != 0) + (n - y) / d);
		else
			puts("-1");
	}
	return 0;
}
