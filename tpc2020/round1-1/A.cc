#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int t; scanf("%d", &t);
	while (t--)
	{
		int x; scanf("%d", &x);
		if (x == 1)
			puts("1");
		else
			printf("%d\n", x / 2);
	}
	return 0;
}
