#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int T; scanf("%d", &T);
	while (T--)
	{
		int n; 
		long long a, b; scanf("%d%lld%lld", &n, &a, &b);
		long long s = a | b;
		for (int i = 2; i <= n; i++)
		{
			swap(a, b);
			b += a;
			if (b > (long long)1e17) break;
			s |= b;
		}
		int ans = 0;
		while (s)
		{
			if ((s & 1) == 0)
				ans++;
			s >>= 1;
		}
		printf("%d\n", ans);

	}
	return 0;
}
