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
		int n, m; scanf("%d%d", &n, &m);
		if (n == m)
			printf("%d\n", n + m);
		else
			printf("%d\n", max(n, m) * 2 - 1);
	}
	return 0;
}
