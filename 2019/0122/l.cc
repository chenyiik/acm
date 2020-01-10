#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	long long t = 0, n = 0, a = 0, b = 0, k = 0;
	scanf("%lld%lld%lld%lld%lld", &t, &n, &a, &b, &k);
	if (n < k)
		return puts("0"), 0;
	long long q = n / 2;
	long long p = q + (n % 2);
	long long s = p * a + q * b;
	long long stu = s / k;
	printf("%lld\n", min(stu, t));
	return 0;
}
