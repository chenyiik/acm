#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
#include <queue>

using namespace std;

const int maxn = int(1e5) + 5;
vector<pair<int, int>> a;
vector<int> v[maxn];

int main()
{
	int X, Y, n; scanf("%d%d%d", &X, &Y, &n);
	while (n--)
	{
		int x, y; scanf("%d%d", &x, &y);
		v[x].push_back(y);
	}
	long long tot = X - 1;
	for (const vector<int> &i : v) if (!i.empty())
	{
		int minv = 0x7fffffff, maxv = -1;
		for (int j : i)
			minv = min(minv, j), maxv = max(maxv, j);
		a.push_back(make_pair(minv, maxv));
		tot += maxv * 2;
	}
	sort(a.begin(), a.end());
	long long ans = tot;
	int down = a.size(), up = 0;
	priority_queue<int, vector<int>, greater<int>> Q;
	for (int line = 0, p = 0; line < Y; line++)
	{
		while (p < a.size() && a[p].first == line)
			down--, Q.push(a[p].second), p++;
		while (!Q.empty() && Q.top() == line)
			up++, Q.pop();
		tot += (up - down) * 2;
		ans = min(tot, ans);
	}
	printf("%lld\n", ans);
	return 0;
}
