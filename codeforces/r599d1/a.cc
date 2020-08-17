#include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

typedef long long LL;

int main()
{
	LL n; scanf("%lld", &n);
	if (n == 1)
		return puts("1"), 0;
	set<LL> S;
	while (n > 1)
	{
		LL m = LL(sqrt(n + 0.5));
		LL f = -1;
		for (int i = 2; i <= m; i++)
			if (n % i == 0)
			{
				S.insert(i);
				n /= f = i;
				break;
			}
		if (f == -1)
			break;
	}
	if (n > 1)
		S.insert(n);
	if (S.size() == 1)
		printf("%lld\n", n);
	else 
		puts("1");
	return 0;
}
