#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

const int maxn = int(2e5) + 5;
vector<int> v[maxn];
bool mark[maxn];

int main()
{
	int n, m; scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++)
	{
		int x, y; scanf("%d%d", &x, &y);
		v[x].push_back(y), v[y].push_back(x);
	}
	int ans = 0;
	for (int r = 1; r <= n; r++) if (!mark[r])
	{
		ans--;
		for (int i = r; i <= r; i++) if (!mark[i])
		{
			ans++;
			queue<int> Q;
			Q.push(i), mark[i] = true;
			while (!Q.empty())
			{
				int u = Q.front(); Q.pop();
				r = max(r, u);
				for (int j : v[u]) if (!mark[j])
					Q.push(j), mark[j] = true;
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}
