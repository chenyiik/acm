#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int x;
	scanf("%d", &x);
	if (x % 4 == 1)
		puts("0 A");
	if (x % 4 == 3)
		puts("2 A");
	if (x % 4 == 2)
		puts("1 B");
	if (x % 4 == 0)
		puts("1 A");
	return 0;
}
