#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int maxn = 3001;
int c[maxn][maxn], ans[maxn];

void init()
{
	ans[0] = c[0][0] = 1;
	for (int i = 1; i < maxn; i++)
	{
		ans[i] = c[i][0] = 1;
		for (int j = 1; j < i; j++)
			ans[i] += c[i][j] = c[i - 1][j - 1] ^ c[i - 1][j];
		ans[i] += c[i][i] = 1;
	}
}

int main()
{
	//init();
	//for (int i = 0; i <= 100; i++)
	//{
		//cout << i << ":\t" << ans[i] << '\t';
		long long tmp, test = 1;
		scanf("%lld", &tmp);
		while (tmp)
			test <<= (tmp & 1LL), tmp >>= 1LL;
		//for (int j = 0; j <= i; j++)
			//cout << c[i][j];
		//cout << test << endl;
		printf("%lld\n", test);
	//}
	return 0;
}
