#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int t; scanf("%d", &t);
	while (t--)
	{
		int n, x, a, b; scanf("%d%d%d%d", &n, &x, &a, &b);
		if (b < a)
			swap(a, b);
		int h = n - b, l = a - 1; 
		printf("%d\n", b - a + min(x, h + l));
	}
	return 0;
}
