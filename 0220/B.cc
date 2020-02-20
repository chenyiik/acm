#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

const int maxn = int(4e5) + 5;
int e[maxn], edge[maxn];
vector<int> G[maxn];

struct cmp { bool operator()(int a, int b) { return e[a] > e[b]; } };

int main()
{
	int n; scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		int d, x;
		scanf("%d%d", &e[i], &d);
		while (d--)
			scanf("%d", &x), G[i].push_back(x), edge[x]++;
	}
	priority_queue<int, vector<int>, cmp> Q;
	for (int i = 1; i <= n; i++) if (!edge[i])
		Q.push(i);
	int ans = 0;
	for (int i = n - 1; i >= 0; i--)
	{
		int nd = Q.top(); Q.pop();
		ans = max(ans, e[nd] + i);
		for (int v : G[nd]) if (!--edge[v])
			Q.push(v);
	}
	printf("%d\n", ans);
	return 0;
}
