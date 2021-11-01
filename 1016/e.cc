#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>

using namespace std;

typedef long long LL;
const int mod = int(1e9) + 7;
LL pow_mod(LL a, LL p, LL n)
{
	if (p == 0)
		return 1;
	LL ans = pow_mod(a, p / 2, n);
	ans = ans * ans % n;
	if (p % 2 == 1)
		ans = ans * a % n;
	return ans;
}
LL inv(LL a, LL n = mod) { return pow_mod(a, n - 2, n); }

const int maxn = int(1e5) + 7;
struct P { int x, y, d; };
P nd[maxn];
vector<P> G[maxn];

LL gcd(LL a, LL b) { return !b ? a : gcd(b, a % b); }

pair<LL, LL> add(pair<LL, LL> a, pair<LL, LL> b)
{
	pair<LL, LL> ans = make_pair(a.first * b.second + b.first * a.second, a.second * b.second);
	LL g = gcd(ans.first, ans.second);
	ans.first /= g;
	ans.second /= g;
	return ans;
}

int main()
{
	int _; scanf("%d", &_);
	while (_--)
	{
		int n, m; scanf("%d%d", &n, &m);
		for (int i = 0; i < n; i++) for (int j = 0; j < m; j++)
		{
			int index = i * m + j;
			nd[index].x = i, nd[index].y = j;
			scanf("%d", &nd[index].d);
		}
		sort(nd, nd + n * m, [](P a, P b){return a.d < b.d;});
		int len = -1, old = 0;
		for (int i = 0; i < n * m; i++)
		{
			if (old != nd[i].d)
				len++, old = nd[i].d;
			G[len].push_back(nd[i]);
		}
		len++;
		pair<LL, LL> pre = make_pair(0, 1);
		for (int i = len - 1; i >= 0; i--)
		{

		}
	}
	return 0;
}
