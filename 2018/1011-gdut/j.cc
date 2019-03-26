#include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>

using namespace std;

int is_prime_2(int nn)
{
	int n = sqrt(0.5 + nn);
	if (n * n != nn)
		return false;
	int m = sqrt(0.5 + n);
	for (int i = 2; i <= m; i++)
	{
		if (n % i == 0)
			return false;
	}
	return true;
}

int f(int n)
{
	for (int l = n, r = n; ; l--, r++)
	{
		if (is_prime_2(l))
			return l;
		if (is_prime_2(r))
			return r;
	}
}

int main()
{
	int t = 0;
	scanf("%d", &t);
	while (t--)
	{
		int n = 0;
		scanf("%d", &n);
		printf("%d\n", f(n));
	}
	return 0;
}
