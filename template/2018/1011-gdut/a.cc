#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int t = 0;
	scanf("%d", &t);
	while (t--)
	{
		int n = 0;
		scanf("%d", &n);
		int ans = 0;
		while (n)
			ans += n /= 2;
		printf("%d\n", ans);
	}
	return 0;
}
