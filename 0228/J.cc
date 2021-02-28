#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int maxn = 500;
bool a[maxn];

int main()
{
	int n; scanf("%d", &n);
	while (n--)
	{
		int x, y; scanf("%d%d", &x, &y);
		for (int i = x; i <= y; i++)
			a[i] = true;
	}
	int ans = 0;
	for (int i = 1; i < 366; i++)
		if (a[i])
			ans++;
	printf("%d\n", ans);
	return 0;
}
