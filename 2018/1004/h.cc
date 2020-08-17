#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <set>

using namespace std;

struct P { string s[3]; };
struct R { string s; int ans; };

int main()
{
	int M0 = 0;
	cin >> M0;
	set<string> S;
	vector<P> V(M0);
	for (int i = 0; i < M0; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cin >> V[i].s[j];
			S.insert(V[i].s[j]);
		}
	}

	int n = 0, root = -1;
	map<string, int> M;
	static R RR[500];
	for (auto it = S.begin(); it != S.end(); ++it, ++n)
	{
		if (*it == "Isenbaev")
			root = n;
		M[*it] = n;
		RR[n] = R{*it, -1};
	}
	vector<int> G[500];
	static int e[500];
	int m = 0;
	while (M0--)
	{
		for (int i = 0; i < 2; i++)
		{
			int u = M[V[M0].s[i]];
			for (int j = i + 1; j < 3; j++)
			{
				int v = M[V[M0].s[j]];
				G[u].push_back(m);
				e[m++] = v;
				G[v].push_back(m);
				e[m++] = u;
			}
		}
	}

	//static int ans[500];
	//memset(ans, -1, sizeof(ans));
	if (root != -1)
	{
		static bool vis[500];
		memset(vis, false, sizeof(vis));
		queue<int> Q;
		Q.push(root);
		//ans[root] = 0;
		RR[root].ans = 0;
		vis[root] = true;
		while (!Q.empty())
		{
			int u = Q.front();
			Q.pop();
			for (int i = 0; i < G[u].size(); i++)
			{
				int v = e[G[u][i]];
				if (vis[v])
					continue;
				Q.push(v);
				//ans[v] = ans[u] + 1;
				RR[v].ans = RR[u].ans + 1;
				vis[v] = true;
			}
		}
	}

	for (int i = 0; i < n; i++)
	{
		cout << RR[i].s << ' ';
		if (RR[i].ans == -1)
			cout << "undefined" << endl;
		else
			cout << RR[i].ans << endl;
	}

	return 0;
}
