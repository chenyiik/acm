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
		for (int i = 0; i < n; i++)
			printf("1%c", " \n"[i + 1 == n]);
	}
	return 0;
}
