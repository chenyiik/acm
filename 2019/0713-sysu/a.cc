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
		int n, s, t;
		scanf("%d%d%d", &n, &s, &t);
		printf("%d\n", 1 + max(n - s, n - t));
	}
	return 0;
}
