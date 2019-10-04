#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int mod = int(1e9) + 7, maxn = int(1e4) + 7;

struct P { int v, d; };

int ans0, ans1, ans2;

vector<P> G[maxn];
void solve(int n)
{
	for (int i = 0; i < n; i++)
		G[i].clear();
	for (int i = 1; i < n; i++)
	{
		int u, v, d;
		scanf("%d%d%d", &u, &v, &d);
		G[u].push_back({v, d});
		G[v].push_back({u, d});
	}
	ans0 = ans1 = ans2 = 0;
}

int main()
{
	for (int n; ~scanf("%d", &n); )
		solve(n);
	return 0;
}
