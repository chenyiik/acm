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
		int n = 0, m = 0;
		scanf("%d%d", &n, &m);
		long long a = 0, b = 0;
		for (int i = 0; i < n; i++)
		{
			int x = 0;
			scanf("%d", &x);
			a += x;
		}
		for (int i = 0; i < m; i++)
		{
			int x = 0;
			scanf("%d", &x);
			b += x;
		}
		puts(n <= m ? "Yes" : "No");
	}
	return 0;
}
