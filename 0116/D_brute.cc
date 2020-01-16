#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int maxn = int(1e5) + 10;
vector<int> v[maxn];
int n, k, ans = 0;
bool vis[100][1000][100];

void brute(int l, int r, int base, int len)
{
	ans = max(ans, len);
	for (int i = l; i <= r; i++)
	{
		for (int j : v[i]) if (j > base)
		{
			if (vis[i][j][len])
				continue;
			vis[i][j][len] = true;
			int ll = i == n ? 1 : i + 1, rr = ll + k;
			if (rr <= n)
				brute(ll, rr, j, len + 1);
			else
				brute(ll, n, j, len + 1), brute(1, rr - n, j, len + 1);
		}
	}
}

int main()
{
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
	{
		int m; scanf("%d", &m);
		while (m--)
		{
			int x; cin >> x;
			v[i].push_back(x);
		}
	}
	brute(1, n, -1, 0);
	cout << ans << endl;
	return 0;
}
