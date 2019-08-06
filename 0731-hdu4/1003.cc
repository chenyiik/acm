#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

typedef long long LL;

int main()
{
	for (int n = 1; n <= 100; n++)
		for (int k = 1; k < n; k++) 
			if (n % k == 0 && k > 1 && n*(n+1)/2%k == 0 && n / k % 2 != 0)
				cout << n << ' ' << k << endl;
	int t;
	scanf("%d", &t);
	while (t--)
	{
		LL n, k;
		scanf("%lld%lld", &n, &k);
		if (n * (n + 1) / 2 % k != 0)
		{
			puts("no");
			continue;
		}
	}
	return 0;
}
