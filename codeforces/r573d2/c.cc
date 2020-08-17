#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

typedef long long ll;

int main()
{
	ll n, k;
	int m;
	scanf("%lld%d%lld", &n, &m, &k);
	queue<ll> Q;
	for (int i = 0; i < m; i++)
	{
		ll x;
		scanf("%lld", &x);
		Q.push(x);
	}
	ll ans = 0, pos = 0;
	while (!Q.empty())
	{
		ll tot = 0;
		while (!Q.empty() && Q.front() <= pos)
			Q.pop(), tot++;
		if (tot)
			ans++, pos += tot;
		else
		{
			ll d = Q.front() - pos;
			pos += k * (d / k + (d % k != 0));
		}
	}
	printf("%lld\n", ans);
	return 0;
}
