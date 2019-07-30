#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

typedef long long LL;

struct P
{
	static const int N = 2;
	LL a[N][N];
	P() { memset(a, 0, sizeof(a)); }
	P(int I)
	{
		memset(a, 0, sizeof(a));
		for (int i = 0; i < N; i++)
			a[i][i] = I;
	}
	P operator*(const P &o) const 
	{
		P t;
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				for (int k = 0; k < N; k++)
					t.a[i][j] += a[i][k] * o.a[k][j];
		return t;
	}
	P operator%(LL k) const
	{
		P t;
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				t.a[i][j] = a[i][j] % k;
		return t;
	}
};

const int mod = static_cast<int>(1e8);
int gcd(int a, int b) { return !b ? a : gcd(b, a % b); }

P pow_mod(P a, LL p, LL n)
{
	if (p == 0)
		return P(1);
	P ans = pow_mod(a, p / 2, n);
	ans = ans * ans % n;
	if (p % 2 == 1)
		ans = ans * a % n;
	return ans;
}

int main()
{
	int a = 0, b = 0;
	scanf("%d%d", &a, &b);
	int g = gcd(a, b);
	P t;
	t.a[0][0] = 0;
	t.a[0][1] = t.a[1][0] = t.a[1][1] = 1;
	t = pow_mod(t, g - 1, mod);
	LL ini[2] = {0, 1}, ans[2];
	ans[0] = t.a[0][0] * ini[0] + t.a[0][1] * ini[1];
	ans[1] = t.a[1][0] * ini[0] + t.a[1][1] * ini[1];
	printf("%lld\n", ans[1]);
	return 0;
}
