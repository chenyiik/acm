#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

map<int, int> M;
const int maxn = 100005;
bool vis[maxn];
int main()
{
	int n, m;scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++)
	{
		int x; scanf("%d", &x);
		M[i] = x;
	}
	for (int i = -1; i >= -m; i--)
	{
		int x; scanf("%d", &x);
		M[i] = x;
	}
	for (pair<int, int> i : M)
		if (!vis[i.second])
		{
			printf("%d ", i.second);
			vis[i.second] = true;
		}
	return 0;
}
