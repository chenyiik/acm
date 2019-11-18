#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

typedef long long LL;

const int maxn = int(2e5) + 5;
int a[maxn];
LL tot[maxn];

int main()
{
	int n, m; scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	sort(a, a + n);
	LL ans = 0;
	for (int i = 0; i < n; i++)
	{
		ans += tot[i % m] += a[i];
		printf("%lld ", ans);
	}
	puts("");
	return 0;
}
