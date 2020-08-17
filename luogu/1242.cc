#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const char *mmp = "ABC";
int n, fr[50], bk[50], ans;
vector<int> st[3], fi[3];

void read();

void dfs(int nu, int u, int v)
{
	//char sss[64];
	//cin.getline(sss, 100);
	//cout << nu << ' ' << u << ' ' << v << endl;
	int w = 3 - u - v;
	for (int i = nu - 1; i > 0; i--)
		if (fr[i] == u || fr[i] == v)
			dfs(i, fr[i], w);
	printf("move %d from %c to %c\n", nu, mmp[u], mmp[v]);
	ans += 1;
	fr[nu] = v;
	st[u].pop_back();
	st[v].push_back(nu);
	return;
}

int main()
{
	read();
	for (int i = n; i > 0; i--)
		if (fr[i] != bk[i])
			dfs(i, fr[i], bk[i]);
	printf("%d\n", ans);
	return 0;
}

void read()
{
	scanf("%d", &n);
	for (int i = 0; i < 3; i++)
	{
		int m = 0, x = 0;
		scanf("%d", &m);
		while (m--)
		{
			scanf("%d", &x);
			fr[x] = i;
			st[i].push_back(x);
		}
	}
	for (int i = 0; i < 3; i++)
	{
		int m = 0, x = 0;
		scanf("%d", &m);
		while (m--)
		{
			scanf("%d", &x);
			bk[x] = i;
			fi[i].push_back(x);
		}
	}
}


