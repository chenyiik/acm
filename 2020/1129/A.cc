#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

long long a[16] = {
	0ll,
	1ll,
	4ll,
	27ll,
	256ll,
	3125ll,
	46656ll,
	823543ll,
	16777216ll,
	387420489ll,
	10000000000ll,
	285311670611ll,
	8916100448256ll,
	302875106592253ll,
	11112006825558016ll,
	437893890380859375ll
};

int main()
{
	for (long long n; ~scanf("%lld", &n); )
	{
		int ans = 0;
		while (ans < 16 && a[ans] <= n)
			ans++;
		ans--;
		printf("%d\n", ans);
	}
	return 0;
}
