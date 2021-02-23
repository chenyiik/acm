#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

typedef long long LL;

int main()
{
	LL n; scanf("%lld", &n);
	LL c = n * (n + 1) / 2;
	printf("%f\n", c / double(n));
	return 0;
}
