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
		int n; scanf("%d", &n);
		printf("%d\n", n);
		for (int i = 1; i <= n; i++)
			printf("%d%c", i, " \n"[i == n]);
	}
	return 0;
}
