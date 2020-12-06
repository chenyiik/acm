#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

const int maxn = int(1e6) + 10;
int a[maxn];

int main()
{
	int T; scanf("%d", &T);
	while (T--)
	{
		int n; scanf("%d", &n);
		for (int i = 0; i < n; i++)
			scanf("%d", &a[i]);
		sort(a, a + n);
		map<int, int> M;
		long long ans = 0;
		for (int i = 0; i < n; i++)
		{
			int &x = a[i];
			if (M.find(x) == M.end()) M[x] = 1;
			else M[x]++;
			ans += M[x] * 2 - 1;
			while (x)
			{
				int bit = 0;
				for (int j = 0; j < 30; j++)
					if ((1 << j) & x)
						bit = j;
				x &= (1 << bit) - 1;
				if (M.find(x) != M.end()) ans += M[x];
			}
		}
		printf("%lld\n", ans);
	}
	return 0;
}
