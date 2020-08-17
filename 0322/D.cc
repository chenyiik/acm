#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <utility>
#include <queue>

using namespace std;

class P
{
private:
	map<string, int> mp;
	int ml;
public:
	P() : ml(0) {}
	int find(const char *s);
} mmp;

char input_s[1000];
int target[105];

const int maxn = 10005;
vector<pair<int, long long>> G[maxn];
queue<int> Q;
struct R { bool vis; int edge; long long dist; } node[maxn];

int main()
{
	mmp.find("English");
	int n, m; scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++)
		scanf("%s", input_s), target[i] = mmp.find(input_s);
	for (int i = 0; i < m; i++)
	{
		scanf("%s", input_s); int x = mmp.find(input_s);
		scanf("%s", input_s); int y = mmp.find(input_s);
		int e; scanf("%d", &e);
		G[x].push_back(make_pair(y, e)), G[y].push_back(make_pair(x, e));
	}
	Q.push(0), node[0] = {true, 0, 0};
	while (!Q.empty())
	{
		int u = Q.front(); Q.pop();
		for (pair<int, long long> v : G[u]) 
			if (!node[v.first].vis)
			{
				node[v.first] = {true, node[u].edge + 1, v.second};
				Q.push(v.first);
			}
			else if (node[u].edge + 1 == node[v.first].edge)
			{
				node[v.first].dist = min(node[v.first].dist, v.second);
			}
	}
	long long ans = 0;
	for (int i = 0; i < n; i++)
	{
		if (!node[target[i]].vis)
			return puts("Impossible"), 0;
		//cout << node[target[i]].dist << endl;
		ans += node[target[i]].dist;
	}
	printf("%lld\n", ans);
	return 0;
}

int P::find(const char *s)
{
	map<string, int>::iterator it = mp.find(s);
	if (it == mp.end())
	{
		mp[s] = ml;
		return ml++;
	}
	else
		return it->second;
}
