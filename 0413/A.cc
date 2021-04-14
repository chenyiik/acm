#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;



int main()
{
	int T; scanf("%d", &T);
	while (T--)
	{
		int n; scanf("%d", &n);
		int a = 0, b = 0, c = 0;
		while (n--)
		{
			int x; scanf("%d", &x);
			if (x < 0) a++;
			else if (x > 0) b++;
			else if (x == 0) c++;
		}
		while (c)
		{
			if (a < b) a++;
			else b++;
			c--;
		}
		if (a == b || (a > b && a - b == 1) || (a < b && b - a == 1))
			puts("Yes");
		else
			puts("No");
	}
	return 0;
}
