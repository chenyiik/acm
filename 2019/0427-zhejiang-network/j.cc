#include <cstdio>
#include <cctype>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

const int maxN = static_cast<int>(1e6) + 7;
vector<int> v[maxN];
bool vis[maxN], wis[maxN];
priority_queue<int, vector<int>, greater<int>> Q;

void dfs(int u)
{
	vis[u] = true;
	for (int i : v[u])
	{
		if (!vis[i])
			dfs(i);
	}
}

void Rd(int &res){
	res=0;
	char c;
	while(c=getchar(),!isdigit(c));
	do{
		res=(res*10)+(c^48);
	}while(c=getchar(),isdigit(c));
}
int main()
{
	int t = 0;
	Rd(t);
	while (t--)
	{
		int n = 0, m = 0;
		Rd(n), Rd(m);
		for (int i = 1; i <= n; i++)
			v[i].clear();
			//vector<int>().swap(v[i]);
		for (int i = 0; i < m; i++)
		{
			int x, y;
			Rd(x), Rd(y);
			v[x].push_back(y);
			v[y].push_back(x);
		}
		//memset(vis, false, sizeof(vis));
		//memset(wis, false, sizeof(wis));
		for (int i = 1; i <= n; i++)
			vis[i] = wis[i] = false;
		queue<int> QQ;
		for (int i = 1; i <= n; i++)
		{
			if (vis[i])
				continue;
			wis[i] = true;
			Q.push(i);
			//dfs(i);
			QQ.push(i);
			vis[i] = true;
			while (!QQ.empty())
			{
				int u = QQ.front();
				QQ.pop();
				for (int j : v[u])
				{
					if (vis[j])
						continue;
					QQ.push(j);
					vis[j] = true;
				}
			}

		}
		printf("%d\n", Q.size());
		bool b = false;
		while (!Q.empty())
		{
			int p = Q.top();
			Q.pop();
			if (b)
				putchar(' ');
			b = true;
			printf("%d", p);
			for (int i : v[p])
			{
				if (wis[i])
					continue;
				wis[i] = true;
				Q.push(i);
			}
		}
		puts("");
	}
	return 0;
}
