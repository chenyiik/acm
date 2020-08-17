#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int maxn = int(2e5) + 5;
int a[maxn];

int main()
{
	int t;
	scanf("%d", &t);
	while (t--)
	{
		int n, m1, m2;
		scanf("%d", &n);
		for (int i = 0; i < n; i++)
			scanf("%d", &a[i]);
		sort(a, a + n, [](int a, int b) { return a > b; });
		int x = n - 2;
		int y = a[1] - 1;
		printf("%d\n", min(x, y));
	}
	return 0;
}
