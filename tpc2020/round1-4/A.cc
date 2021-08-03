#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int maxn = int(1e3) + 5;
int a[maxn][maxn];

typedef long long LL;

int main()
{
	int _; scanf("%d", &_);
	while (_--)
	{
		int n; scanf("%d", &n);
		LL sum = 0; 
		int _max = 0, _min = 0x7fffffff;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
			{
				scanf("%d", &a[i][j]);
				sum += a[i][j] * 2;
				if (i == j && i + j + 1 == n)
				{
					sum += a[i][j] * 2;
					_min = min(_min, a[i][j]);
				}
				else if (i == j || i + j + 1 == n)
				{
					sum += a[i][j];
					_min = min(_min, a[i][j]);
				}
				else 
					_max = max(_max, a[i][j]);
			}
		if (n == 1)
			;
		if (n % 2 == 0)
		{
			if (_max > _min)
				sum = sum + _max - _min;
		}
		else
		{
			int tmp = a[n / 2][n / 2];
			int p = 0x7fffffff, q = 0;
			for (int i = 0; i < n; i++)
				for (int j = 0; j < n; j++)
					if (i == j && i + j + 1 == n)
						;
					else if (i == j || i + j + 1 == n)
						p = min(p, a[i][j]), q = max(q, a[i][j]);
			sum = max(max(sum, sum - 2 * tmp + 2 * _max),
					max(sum - p + _max, sum + q - tmp));
		}
		printf("%lld\n", sum);
	}
	return 0;
}
