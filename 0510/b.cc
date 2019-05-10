#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

typedef long long LL;

const int maxN = static_cast<int>(1e7) + 7;
bool vis[maxN];

void fuck(int n)
{
	
}

int main()
{

	LL a, b, c, d;
	scanf("%lld%lld%lld%lld", &a, &b, &c, &b);
	LL ans = (b - a + 1) * (d - c + 1);
	for (int i = c; i <= d; i++)
		fuck(i);
	return 0;
}
