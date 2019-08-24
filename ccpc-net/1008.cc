#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

typedef long long LL;

const int maxn = int(1e5) + 15;
LL a[maxn];

int main()
{
	int _; scanf("%d", &_);
	while (_--)
	{
		LL n, k; scanf("%lld%lld", &n, &k);
		for (int i = 0; i < n; i++)
			scanf("%lld", &a[i]);
		sort(a, a + n);
		LL T = k + a[0];
		vector<LL> v[3];
		queue<LL> Q;
		for (int i = 1; i < n; i++)
		{
			T += max(k, a[i]);
			if (a[i] < k)
				Q.push(a[i]);
			else if (a[i] < 2 * k)
				v[1].push_back(a[i] - k);
			else
				v[2].push_back(a[i]);
		}
		for (LL i : v[2])
		{
			LL d = i / k - 1, m = i % k;
			while (d && !Q.empty())
			{
				T -= k - Q.front();
				Q.pop();
				d--;
			}
			v[1].push_back(m);
		}
		sort(v[1].begin(), v[1].end(), [](LL a, LL b) { return a > b;});
		for (LL i : v[1])
		{
			if (Q.empty() || k - Q.front() <= k - i)
				break;
			else 
				T += k - i, T -= k - Q.front(), Q.pop();
		}
		printf("%lld\n", T);
	}
	return 0;
}
