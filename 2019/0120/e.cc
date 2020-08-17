#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int maxN = static_cast<int>(2e5);
int n = 0, m = 0, t = 0;
int a[maxN];

int main()
{
	int c = 0;
	scanf("%d", &c);
	while (c--)
	{
		scanf("%d%d%d", &n, &m, &t);
		int max_p = 0;
		for (int i = 0; i < n; i++)
		{
			scanf("%d", a[i]);
			max_p = max(max_p, a[i]);
		}
		int l = 1, r = max_p + 1;
		while (l < r - 1)
		{
		}
		
	}
	return 0;
}
