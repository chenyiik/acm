#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int _; scanf("%d", &_);
	while (_--)
	{
		int a, b, c, d; scanf("%d%d%d%d", &a, &b, &c, &d);
		printf("%d\n", max(a + b, c + d));
	}
	return 0;
}
