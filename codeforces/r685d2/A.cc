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
		if (n < 4)
			printf("%d\n", n - 1);
		else if (n % 2 == 0)
			puts("2");
		else
			puts("3");
	}
	return 0;
}
