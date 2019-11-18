#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
 
using namespace std;
 
int gcd(int a, int b) { return !b ? a : gcd(b, a % b); }
 
int main()
{
	int t; scanf("%d", &t);
	while (t--)
	{
		int a, b; scanf("%d%d", &a, &b);
		if (gcd(a, b) == 1)
			puts("Finite");
		else
			puts("Infinite");
	}
	return 0;
}
