#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

typedef long long LL;

const int maxn = int(1e5) + 5;
LL a[maxn], b[maxn];

void solve()
{
	int n, m; scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++) scanf("%lld", &a[i]);
	b[0] = a[0] == -1 ? 0 : a[0];
	b[1] = a[1] == -1 ? 0 : a[1];
	for (int i = 2; i < n; i++)
	{
		if (a[i] > -1) b[i] = a[i];
		bool x = a[i - 2] > -1;
		bool y = a[i - 1] > -1;
		bool z = a[i - 0] > -1;
		if (x && y && z)
		{
			LL tot = b[i - 2] + b[i - 1] + b[i];
			if (tot < m)
			{
				puts("Impossible");
				return;
			}
		}
		else if (z)
		{
			LL tot = b[i - 2] + b[i - 1] + b[i];
			if (tot < m)
			{
				if (!y) b[i - 1] += m - tot;
				else b[i - 2] += m - tot;
			}
		}
		else if (!z)
		{
			b[i] = 0;
			LL tot = b[i - 2] + b[i - 1] + b[i];
			if (tot < m) b[i] += m - tot;
		}
	}
	LL ans = 0;
	for (int i = 0; i < n; i++)
	{
		ans += b[i];
		//cout << b[i] << ' ';
	}
	//cout << endl;
	printf("%lld\n", ans);
}

int main()
{
	int _; scanf("%d", &_);
	while (_--)
		solve();
	return 0;
}
