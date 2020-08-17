#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int n, k;
	scanf("%d%d", &n, &k);
	long long ans = 0, pre = 0;
	for (int i = 0; i < n; i++)
	{
		long long d;
		scanf("%lld", &d);
		if (d + pre == 0)
			;
		else if (d + pre < k)
		{
			if (pre == 0)
				pre = d;
			else
			{
				ans++;
				pre = 0;
			}
		}
		else
		{
			ans += (d + pre) / k;
			pre = (d + pre) % k;
		}
	}
	if (pre > 0)
		ans++;
	printf("%lld\n", ans);
	return 0;
}
