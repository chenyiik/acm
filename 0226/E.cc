#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int n = 0, sum = 0, x;
	while (~scanf("%d", &x))
		n++, sum += x;
	sum -= (n - 1);
	printf("%d\n", sum);
	return 0;
}
