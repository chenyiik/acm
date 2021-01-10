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
		int x, y; scanf("%d%d", &x, &y);
		if (x > y)
			puts("Bashar");
		else if (x == y)
			puts("Iskandar");
		else
			puts("Hamada");
	}
	return 0;
}
