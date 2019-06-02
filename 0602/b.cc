#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef long long LL;

const int maxn = (int)1e5 + 10;

vector<int> v[maxn];
int lim[maxn];
int sum[maxn];

int gcd(LL a, LL b) { return !b ? a : gcd(b, a % b); }

int main()
{
	int t;
	scanf("%d", &t);
	while (t--)
	{
		int n, m;
		scanf("%d%d", &n, &m);
		for (int i = 1; i <= m; i++)
		{
			v[i].clear();
			//vector<int>().swap(v[i]);
			v[i].push_back(0);
		}
		for (int i = 1; i <= m; i++)
			scanf("%d", &lim[i]);
		for (int i = 1; i <= n; i++)
		{
			int x, y;
			scanf("%d%d", &x, &y);
			v[y].push_back(x);
		}
		for (int i = 1; i <= m; i++)
		{
			sort(v[i].begin() + 1, v[i].end(), [](int a, int b) { return a > b; });
			v[i].push_back(0);
		}
		memset(sum, 0, sizeof(sum));
		for (int i = 1; i <= m; i++)
		{
			for (int j = 1; j < v[i].size() - 1; j++)
			{
				if (j < lim[i])
					v[i][j + 1] += v[i][j];
				else
					sum[j] += v[i][j];
			}
		}
		LL ansS = 0, ansC = 1, nowS = 0;
		for (int i = 1; i <= n; i++)
		{
			nowS += sum[i];
			if (nowS * ansC > ansS * i)
				ansS = nowS, ansC = i;
		}
		LL g = gcd(ansS, ansC);
		ansS /= g, ansC /= g;
		printf("%lld/%lld\n", ansS, ansC);
	}
	return 0;
}
