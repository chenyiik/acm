#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int maxn = int(1e5) + 10;
char s[maxn];

int a[30], b[30], c[30][30];

bool check(int n, int k)
{
	for (int i = 0; i < k; i++)
		if (a[i] - b[i] > 1)
			return false;
	for (int i = k; i < n; i++)
		if (a[i] - b[i] > 0)
			return false;

	//for (int i = 0; i < n; i++)
	//	cout << a[i];
	//cout << endl;
	//for (int i = 0; i < n; i++)
	//	cout << b[i];
	//cout << endl;
	//cout << "yes" << endl;

	return true;
}

typedef long long LL;
const LL mod = int(1e9) + 7;

LL pow_mod(LL a, LL p, LL n = mod)
{
	if (p == 0)
		return 1;
	LL ans = pow_mod(a, p / 2, n);
	ans = ans * ans % n;
	if (p % 2 == 1)
		ans = ans * a % n;
	return ans;
}

int main()
{
	int T; scanf("%d", &T);
	while (T--)
	{
		scanf("%s", s);
		LL n = strlen(s), k = 0;
		for (int i = 0; i < n; i++)
			if (s[i] == '1')
				k++;
		LL ans = 1;
		for (int i = 1; i < n; i++)
			ans = ans * i % mod;
		if (k == 0)
			ans = ans * n % mod;
		else
		{
			LL p = pow_mod(2, k - 1) * k % mod;
			LL q = (n - k) * pow_mod(2, k) % mod;
			//cout << ans << ' ' << p << ' ' << q << endl;
			ans = ans * (p + q) % mod;
		}
		printf("%lld\n", ans);
	}
	//c[0][0] = 1;
	//for (int n = 1; n <= 7; n++)
	//{
	//	cout << n << ": ";
	//	for (int k = 0; k <= n; k++)
	//	{
	//		for (int i = 0; i < n; i++)
	//			a[i] = i, b[i] = i;
	//		int ans = 0;
	//		do
	//		{
	//			do
	//			{
	//				if (check(n, k))
	//					ans++;
	//			} while (next_permutation(b, b + n));
	//		} while (next_permutation(a, a + n));
	//		c[n][k] = ans;
	//		printf("%10lld ", ans / c[n - 1][0]);
	//		//cout << n << ' ' << k << ' ' << ans << endl;
	//	}
	//	cout << endl;
	//}
	return 0;
}
