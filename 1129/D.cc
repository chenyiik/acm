#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

typedef long long LL;
const int mod = int(1e9) + 7;

struct Mat
{
	LL a[4][4];
	Mat operator*(const Mat &o) const
	{
		Mat ret;
		memset(ret.a, 0, sizeof(ret.a));
		for (int i = 0; i < 4; i++)
			for (int j = 0; j < 4; j++)
				for (int k = 0; k < 4; k++)
					ret.a[i][j] = ((ret.a[i][j] + a[i][k] * o.a[k][j] % mod) + mod) % mod;
		return ret;
	}
};

Mat b, c;

Mat pow_mod(Mat a, LL p)
{
	if (p == 0) return c;
	Mat ans = pow_mod(a, p / 2);
	ans = ans * ans;
	if (p % 2 == 1) ans = ans * a;
	return ans;
}

int main()
{
	c.a[0][0] = c.a[1][1] = c.a[2][2] = c.a[3][3] = 1;
	b.a[0][1] = b.a[1][2] = b.a[2][3] = b.a[3][1] = b.a[3][3] = 1;
	b.a[3][0] = -1, b.a[3][2] = 5;
	for (LL n; ~scanf("%lld", &n); )
	{
		Mat s; s.a[0][0] = 1, s.a[1][0] = 5, s.a[2][0] = 11, s.a[3][0] = 36;
		if (n <= 4)
			printf("%lld\n", s.a[n - 1][0]);
		else
			printf("%lld\n", (pow_mod(b, n - 4) * s).a[3][0]);
	}
	return 0;
}
