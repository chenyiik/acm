#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int maxN = 2005, mod = static_cast<int>(1e9 + 7);
//long long c[maxN][maxN], p[maxN][maxN];

void init(int n = maxN)
{
	//for (int i = 0; i < n; i++)
	//{
		//c[i][0] = 1LL;
		//for (int j = 1; j <= i; j++)
			//c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % mod;
	//}
	//for (int i = 0; i < n; i++)
	//{
		//p[i][0] = 1LL;
		//for (int j = 1, k = i; j <= i; j++, k--)
			//p[i][j] = k[i][j - 1] * k % mod;
	//}
	for (int i = 0; i < n; i++)
	{
		p[i][0] = 1LL;
		for (int j = 1; j < n; j++)
			p[i][j] = p[i][j - 1] * i % mod;
	}
}

int main()
{
	init();
	int m = 0, n = 0;
	while (~scanf("%d%d", &m, &n))
	{
		int ans = (p[m - 1][n] + p[m - 1][n - 1] * n % mod) % mod;
		printf("%d\n", ans);
	}
	return 0;
}
