#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

int a[55], b[55];

int main()
{
	int _; scanf("%d", &_);
	while (_--)
	{
		int m; scanf("%d", &m);
		for (int i = 0; i < m; i++)
			scanf("%d", &a[i]);
		for (int i = 0; i < m; i++)
			scanf("%d", &b[i]);
		int ans = -1;
		for (int i = 0; i < m; i++)
			if (a[i] * 3 < b[i])
			{
				ans = i + 1;
				break;
			}
		printf("%d\n", ans);
	}
	return 0;
}
