#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

bool is_prime(long long n)
{
	for (long long i = 2; i * i <= n; i++)
		if (n % i == 0)
			return false;
	return true;
}

long long fact(long long n, long long p)
{
	long long ans = 1;
	for (int i = 1; i <= n; i++)
		ans = ans * i % p;
	return ans;
}

int main()
{
	long long j = 2;
	for (long long i = 3LL; i <= 1010LL; i++)
	//for (long long i = int(1e9)-100; i <= int(1e9)+10; i++)
	{
		if (is_prime(i))
		{
			if (i - j == 10)
				cout << j << ' ' << i << ' ' << fact(j, i) << endl;
			j = i;
		}
	}
	return 0;
}
