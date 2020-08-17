#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

typedef long long LL;

const int maxn = int(1e5);

LL dp[maxn + 5], mod = 998244353;

void init()
{
	dp[1] = dp[2] = dp[3] = 1, dp[4] = 2;
	for (int i = 5; i <= maxn; i++)
		dp[i] = (dp[i - 1] + dp[i - 3]) % mod;
}

LL f()
{
	int L = 1, x, y, R;
	scanf("%d%d%d", &R, &x, &y);
	if (x + 1 == y)
		return x == L || y == R ? 1 : 0;
	if (x != L)
		x++;
	if (y != R)
		y--;
	int len = y - x + 1;
	return dp[len];
}

int main()
{
	init();
	int t;
	scanf("%d", &t);
	while (t--)
		printf("%lld\n", f());
	return 0;
}
