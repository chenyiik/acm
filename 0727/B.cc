#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

const int maxn = int(1e5) + 5;
queue<int> Q[maxn * 2];
int vis[maxn];
int ans;

void po(int index)
{
	//cout << index << endl;
	if (Q[index].empty())
		return;
	int u = Q[index].front(); Q[index].pop();
	//cout << u << ' ' << vis[u] << endl;
	if (vis[u] == -1)
		vis[u] = index;
	else
	{
		//cout << '\t' << u << endl;
		ans++;
		int j = vis[u];
		po(j);
		po(index);
	}
}

int main()
{
	int T; scanf("%d", &T);
	while (T--)
	{
		int n, k; scanf("%d%d", &n, &k);
		for (int i = 1; i <= n; i++)
			vis[i] = -1;
		for (int i = 0; i < k; i++)
			Q[i] = queue<int>();
		ans = 0;
		for (int i = 0; i < k; i++)
		{
			int m; scanf("%d", &m);
			for (int j = 0; j < m; j++)
			{
				int x; scanf("%d", &x);
				Q[i].push(x);
			}
		}
		for (int i = 0; i < k; i++)
			po(i);
		//cout << ans << endl;
		if (ans % 2 == 1)
			puts("Kelly");
		else
			puts("Nacho");
	}
	return 0;
}
