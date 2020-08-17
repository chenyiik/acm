#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int t;
	scanf("%d", &t);
	while (t--)
	{
		int n, x;
		scanf("%d%d", &n, &x);
		printf("%d\n", x * 2);
	}
	return 0;
}
