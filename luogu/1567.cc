#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int n = 0;
	scanf("%d", &n);
	int ans = 1, cmp = 0x7fffffff, cnt = 1;
	while (n--)
	{
		int x = 0;
		scanf("%d", &x);
		if (x > cmp)
			ans = max(ans, ++cnt);
		else
			cnt = 1;
		cmp = x;
	}
	printf("%d", ans);
	return 0;
}
