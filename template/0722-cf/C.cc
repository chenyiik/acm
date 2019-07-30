#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int maxn = int(3e5) + 5;
int a[maxn];

int main()
{
	int n, k, t, minv, maxv;
	scanf("%d%d%d", &n, &k, &t);
	n--, k--, minv = t, maxv = t;
	for (int i = 0; i < n; i++) 
	{
		scanf("%d", &maxv);
		a[i] = maxv - t;
		t = maxv;
	}
	sort(a, a + n, [](int a, int b) { return a > b; });
	int tot = 0;
	for (int i = 0; i < k; i++)
		tot += a[i];
	printf("%d\n", maxv - minv - tot);
	return 0;
}
