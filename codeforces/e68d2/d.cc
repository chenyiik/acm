#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

int gcd(int a, int b) { return !b ? a : gcd(b, a % b); }
int gcd(int a, int b, int c) { return gcd(a, gcd(b, c)); }

int main()
{
	int t;
	scanf("%d", &t);
	while (t--)
	{
		int n, k;
		scanf("%d%d", &n, &k);
		if (k % 3 != 0)
			puts(n % 3 == 0 ? "Bob" : "Alice");
		else if (k == 3)
			puts(n % 4 == 0 ? "Bob" : "Alice");
		else
		{
			//puts(n % 3 == 0 && n % k != 0 ? "Bob" : "Alice");
			int d = n % (k + 1);
			puts(d % 3 == 0 && d != k ? "Bob" : "Alice");
		}
	}
	return 0;
}
