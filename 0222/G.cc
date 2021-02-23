#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

typedef long long LL;

int main()
{
	LL m, a, b, c; scanf("%lld%lld%lld%lld", &m, &a, &b, &c);
	puts(a % (m + 1) == 0 && b % (m + 1) == 0 && c % (m + 1) == 0 ? "Danftito" : "Tomaz");
	return 0;
}
