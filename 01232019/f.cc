#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int maxN = 10005;
vector<int> v[maxN];
int chid[maxN], N, nod;
long long multy[maxN], ans;

long long mul(long long a[], int n)
{
	int sum = 0, ans = 0;
	for (int i = 0; i < n; i++)
	{
		ans += sum * a[i];
		sum += a[i];
	}
	return ans;
}

int dfs1(int u, int fa)
{
	chid[u] = multy[u] = 0;
	for (int i = 0; i < v[u].size(); i++)
	{
		if (v[u][i] != fa)
			chid[u] += dfs1(v[u][i], u);
	}
	static long long a[maxN];
	for (int i = 0; i < v[u].size(); i++)
		a[i] = v[u][i] == fa ? 0 : chid[v[u][i]] + 1;
	multy[u] = mul(a, v[u].size());
	return chid[u] + 1;
}

void dfs2(int u, int fa)
{
	for (int i = 0; i < v[u].size(); i++)
	{
		if (v[u][i] != fa)
		{
			long long tmp = multy[v[u][i]] + (long long)chid[v[u][i]] * (N - 1 - chid[v[u][i]]);
			if (tmp > ans)
			{
				ans = tmp;
				nod = v[u][i];
			}
			dfs2(v[u][i], u);
		}
	}
}

int main()
{
	int n = 0;
	scanf("%d", &n);
	N = n + 1;
	for (int i = 0; i < n; i++)
	{
		int x = 0, y = 0;
		scanf("%d%d", &x, &y);
		v[x].push_back(y);
		v[y].push_back(x);
	}
	dfs1(0, -1);
	ans = multy[0];
	nod = 0;
	dfs2(0, -1);
	printf("%lld ", ans);
	dfs1(nod, -1);
	static long long a[maxN];
	ans = 0;
	if (v[nod].size() > 1)
	{
		for (int i = 0; i < v[nod].size(); i++)
			a[i] = chid[v[nod][i]] + 1;
		//for (int i = 0; i < v[nod].size(); i++)
			//cout << a[i] << ' ';
		//cout << endl;
		sort(a, a + v[nod].size(), [](int a, int b) { return a > b; });
		a[1] += a[0];
		ans = mul(a + 1, v[nod].size() - 1);
	}
	printf("%lld\n", ans);
	//for (int i = 0; i <= n; i++)
	//{
		//cout << chid[i] << ' ' << multy[i] << endl;
	//}
	return 0;
}
