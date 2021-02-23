#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

typedef long long LL;

const LL mod = int(1e9) + 7, cc[9][9] = {
	{ 1, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 1, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 1, 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 1, 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 1, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 0, 1, 0, 0, 0 },
	{ 0, 0, 0, 0, 0, 0, 1, 0, 0 },
	{ 0, 0, 0, 0, 0, 0, 0, 1, 0 },
	{ 0, 0, 0, 0, 0, 0, 0, 0, 1 }
}, bb[9][9] = {
	{ 1, 0, 0, 1, 0, 0, 1, 0, 0 },
	{ 1, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 1, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 1, 0, 0, 1, 0, 0, 1, 0 },
	{ 0, 1, 0, 0, 1, 0, 0, 0, 0 },
	{ 0, 1, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 1, 0, 0, 1, 0, 0, 1 },
	{ 0, 0, 1, 0, 0, 1, 0, 0, 1 },
	{ 0, 0, 1, 0, 0, 1, 0, 0, 1 }
};

struct P
{
	LL a[9][9];
	P() { memcpy(a, cc, sizeof(a)); }
	P(const LL arr[][9]) { memcpy(a, arr, sizeof(a)); }
	P operator*(const P &o) const {
		P ans;
		memset(ans.a, 0, sizeof(a));
		for (int i = 0; i < 9; i++)
			for (int j = 0; j < 9; j++)
				for (int k = 0; k < 9; k++)
				{
					ans.a[i][j] += a[i][k] * o.a[k][j];
					ans.a[i][j] %= mod;
				}
		return ans;
	}
	void show() const {
		for (int i = 0; i < 9; i++)
		{
			for (int j = 0; j < 9; j++)
				cout << a[i][j] << ' ';
			cout << endl;
		}
	}
} const b(bb);

P my_pow(P a, LL p);

int main()
{
	LL n; scanf("%lld", &n);
	P k = my_pow(b, n - 2);
	LL ans = 0;
	for (int i = 0; i < 9; i++)
		for (int j = 0; j < 9; j++)
			ans = (ans + k.a[i][j]) % mod;
	printf("%lld\n", ans);
	return 0;
}

P my_pow(P a, LL p)
{
	if (p == 0)
		return P();
	P ans = my_pow(a, p / 2);
	ans = ans * ans;
	if (p % 2 == 1)
		ans = ans * a;
	return ans;
}
