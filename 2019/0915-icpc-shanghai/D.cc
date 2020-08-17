#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;
typedef long long LL;
const LL mod = LL(1e9) + 7;

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
LL inv(LL a, LL n = mod) { return pow_mod(a, n - 2, n); }

LL f[3005];
void init()
{
	f[0] = 1;
	for (int i = 1; i < 3003; i++)
		f[i] = f[i - 1] * i % mod;
}

LL calc_ans(const int a[], int len, int n)
{
	LL ans = f[n];
	for (int i = 0; i < len; i++)
		ans = ans * inv(f[a[i]]) % mod;
	return ans;
}

LL get_ans(const int a[], int len, int n)
{
	static int vis[3005]; memset(vis, -1, sizeof(vis));
	static int cnt[200], tn; cnt[(tn = 0)++] = n - len;
	for (int i = 0; i < len; i++)
		if (vis[a[i]] == -1)
			cnt[vis[a[i]] = tn++] = 1;
		else
			cnt[vis[a[i]]]++;
	return calc_ans(cnt, tn, n);
}

LL ans[3005];
int a[200], len = 0, pi = 1, sig = 0;
void dfs(int st)
{
	for (int i = st; i < 3003; i++)
		if (pi * i - (sig + i) + (len + 1) < 7000)
		{
			pi *= i, sig += i, a[len++] = i;
			int n = (pi - sig + len);
			if(n >= 2 && n <= 3000)
				ans[n] = (ans[n] + get_ans(a, len, n)) % mod;
			dfs(i);
			pi /= i, sig -= i, len--;
		}
		else
			break;
}

int main()
{
	init();
	dfs(2);
	int _; scanf("%d", &_);
	while (_--)
	{
		int _; scanf("%d", &_);
		printf("%lld\n", ans[_]);
	}
	return 0;
}
