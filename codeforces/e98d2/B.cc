#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int maxn = int(1e5) + 5;
long long a[maxn];

int main()
{
	int T; scanf("%d", &T);
	while (T--)
	{
		int n; scanf("%d", &n);
		long long maxv = 0, sum = 0;
		for (int i = 0; i < n; i++)
		{
			scanf("%lld", &a[i]);
			sum += a[i], maxv = max(maxv, a[i]);
		}
		long long ans0 = maxv * (n - 1) - sum;
		long long ans1 = (sum / (n - 1) + (sum % (n - 1) ? 1 : 0)) * (n - 1) - sum;
		printf("%lld\n", max(ans0, ans1));
	}
	return 0;
}
