#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <map>
#include <queue>

using namespace std;

typedef long long LL;
typedef unsigned long long ULL;

struct P { ULL value, id; };

ULL a[40];
int ans[40];

int main()
{
	int n; ULL sum; scanf("%d%llu", &n, &sum);
	for (int i = 0; i < n; i++)
		scanf("%llu", &a[i]);
	if (sum == 0)
	{
		for (int i = 0; i < n; i++)
			putchar('0');
		return puts(""), 0;
	}
	if (n == 1)
		return puts("1"), 0;
	int m = n / 2;
	map<ULL, ULL> M; queue<P> Q[2]; int x = 0;
	Q[x].push({0, 0});
	for (int i = n - 1; i >= m; i--)
	{
		while (!Q[x].empty())
		{
			P p = Q[x].front(); Q[x].pop();
			Q[x ^ 1].push({p.value, p.id << 1});
			Q[x ^ 1].push({p.value + a[i], (p.id << 1) | 1});
		}
		x ^= 1;
	}
	while (!Q[x].empty())
		M[Q[x].front().value] = Q[x].front().id, Q[x].pop();
	Q[x].push({0, 0});
	for (int i = 0; i < m; i++)
	{
		while (!Q[x].empty())
		{
			P p = Q[x].front(); Q[x].pop();
			Q[x ^ 1].push({p.value, p.id << 1});
			Q[x ^ 1].push({p.value + a[i], (p.id << 1) | 1});
		}
		x ^= 1;
	}
	while (!Q[x].empty())
	{
		P p = Q[x].front(); Q[x].pop();
		if (M.find(sum - p.value) != M.end())
		{
			for (int i = m - 1; i >= 0; i--)
				ans[i] = p.id & 1, p.id >>= 1;
			p.id = M[sum - p.value];
			for (int i = m; i < n; i++)
				ans[i] = p.id & 1, p.id >>= 1;
			for (int i = 0; i < n; i++)
				printf("%d", ans[i]);
			return puts(""), 0;
		}
	}
	return 0;
}
