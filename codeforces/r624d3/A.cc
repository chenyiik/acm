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
		int a, b; scanf("%d%d", &a, &b);
		if (a == b)
			puts("0");
		else if (a < b)
		{
			if (a % 2 == b % 2)
				puts("2");
			else
				puts("1");
		}
		else
		{
			if (a % 2 == b % 2)
				puts("1");
			else
				puts("2");
		}
	}
	return 0;
}
