#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

typedef long long LL;

int main()
{
	int n;
	scanf("%d", &n);
	LL ans = 0, tmp = 0;
	map<int, int> M;
	for (int i = 1; i <= n; i++)
	{
		int x; scanf("%d", &x);
		tmp += i;
		if (M.find(x) != M.end())
			tmp -= M[x];
		M[x] = i;
		ans += tmp;
		//fprintf(stderr, "%lld %lld\n", ans, tmp);
	}
	printf("%lld\n", ans);
	return 0;
}
