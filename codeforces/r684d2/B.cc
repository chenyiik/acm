#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int maxn = int(2e5) + 5;
int a[maxn];

int main()
{
	int T; scanf("%d", &T);
	while (T--)
	{
		int n, k; scanf("%d%d", &n, &k);
		for (int i = 0; i < n * k; i++)
			scanf("%d", &a[i]);
		sort(a, a + n * k);
		long long sum = 0;
		for (int i = k * (n / 2 + n % 2 - 1); i < n * k; i += n / 2 + 1)
		{
			sum += a[i];
			//cout << i << ' ' << a[i] << ' ' << sum << endl;
		}
		printf("%lld\n", sum);
	}
	return 0;
}
