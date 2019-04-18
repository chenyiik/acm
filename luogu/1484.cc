#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

typedef long long LL;

const int N = 500005;
int a[N];
bool vis[N];

struct P
{
	int value, id;
	bool operator<(const P &o) const { return value < o.value || (value == o.value && id < o.id); }
};

int main()
{
	int n = 0, k = 0;
	scanf("%d%d", &n, &k);
	priority_queue<P> Q;
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
		Q.push({a[i], i});
	}
	LL ans = 0;
	while (k && !Q.empty())
	{
		P p = Q.top();
		Q.pop();
		if (vis[p.id] || p.value <= 0)
			continue;
		vis[p.id] = vis[p.id - 1] = vis[p.id + 1] = true;
		ans += p.value;
		k--;
		Q.push({a[p.id - 1] + a[p.id + 1] - a[p.id], p.id + n});
	}
	printf("%lld\n", ans);
	return 0;
}
