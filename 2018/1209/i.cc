#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int n = 0;
	scanf("%d", &n);
	int ans = 0, a = 0, b = 0, c = 0;
	while (n--)
	{
		a = b;
		b = c;
		scanf("%d", &c);
		if (a == 1 && b == 0 && c == 1)
		{
			c = 0;
			ans++;
		}
	}
	printf("%d\n", ans);
	return 0;
}
