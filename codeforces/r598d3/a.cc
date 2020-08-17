#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int q; scanf("%d", &q);
	while (q--)
	{
		int a, b, n, s;
		scanf("%d%d%d%d", &a, &b, &n, &s);
		int d = min(a, s / n);
		puts(s - d * n <= b ? "YES" : "No");
	}
	return 0;
}
