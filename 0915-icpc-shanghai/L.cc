#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

long long f(long long n) { return n * (n + 1) / 2; }

int main()
{
	int __; scanf("%d", &__);
	for (int _ = 1; _ <= __; _++)
	{
		int n, b; scanf("%d%d", &n, &b);
		static int B[30];
		B[0] = 1, n++;
		for (int i = 1; B[i - 1] <= n * b * b; i++)
			B[i] = B[i - 1] * b;
		long long ans = 0;
		for (int i = 1; B[i] <= n * b; i++)
		{
			ans += (n / B[i]) * (B[i - 1] * f(b - 1));
			ans += B[i - 1] * f(n % B[i] / B[i - 1] - 1);
			ans += (long long)(n % B[i] / B[i - 1]) * (n % B[i] % B[i - 1]);
			//cout << i << ' ' << ans << endl;
		}
		printf("Case #%d: %lld\n", _, ans);
	}
	return 0;
}
