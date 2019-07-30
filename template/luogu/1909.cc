#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int n = 0;
	scanf("%d", &n);
	int ans = 0x7fffffff;
	for (int i = 0; i < 3; i++)
	{
		int num, cost;
		scanf("%d%d", &num, &cost);
		ans = min(ans, cost * (n / num + (n % num != 0)));
	}
	printf("%d\n", ans);
	return 0;
}
