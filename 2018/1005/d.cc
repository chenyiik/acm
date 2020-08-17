#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int maxN = 5007, mod = static_cast<int>(1e9) + 7;
//int c[maxN][maxN];
int **c;

void init(int n = 5000)
{
	c = new int*[5007];
	//memset(c, 0, sizeof(c));
	c[0] = new int[5];
	c[0][0] = 1;
	for (int i = 1; i <= n; i++)
	{
		c[i] = new int[i + 5];
		c[i][0] = c[i][i] = 1;
		for (int j = 1; j < i; j++)
			c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % mod;
	}
}

int main()
{
	init();
	static int a[maxN];
	int n = 0, t = 0;
	scanf("%d%d", &n, &t);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	int k = 0, x = 0;
	scanf("%d%d", &k, &x);
	int value = a[k];
	sort(a + 1, a + n + 1);
	int left = x - 1, right = t - x;
	int le = 0, eq = -1, ge = 0;
	for (int i = 1; i <= n; i++)
	{
		if (a[i] < value)
			le++;
		else if (a[i] == value)
			eq++;
		else
			ge++;
	}
	//cout << left << ' ' << right << endl;
	//cout << le << ' ' << eq << ' ' << ge << endl;
	long long ans = 0;
	for (int i = max(0, left - le); i <= eq; i++)
	{
		for (int j = max(0, right - ge); j <= eq - i; j++)
		{
			int L = left - i, R = right - j;
			if (L < 0 || R < 0)
				continue;
			//cout << i << ' ' << j << endl;
			long long tmp1 = (long long)c[le][L] * (long long)c[ge][R] % mod, tmp2 = c[eq][i + j];
			ans += tmp1 * tmp2;
			ans %= mod;
		}
	}
	printf("%lld\n", ans);
	return 0;
}
