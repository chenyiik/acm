#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
#include <queue>
#include <set>

using namespace std;

pair<int, int> fuck(const vector<int> &v, int low, int high);

const int maxn = int(1e5) + 10;
vector<int> v[maxn];

struct P
{
	int x, y, dist;
	bool operator<(const P &o) const 
	{
		return x > o.x || (x == o.x && dist < o.dist);
	}
};

int main()
{
	int n, l; scanf("%d%d", &n, &l);
	for (int i = 0; i < n; i++)
	{
		int x, y; scanf("%d%d", &x, &y);
		v[x].push_back(y);
	}
	v[l].push_back(0);
	for (int i = 1; i < l; i++)
		sort(v[i].begin(), v[i].end());
	priority_queue<P> Q;
	set<pair<int, int>> S;
	Q.push({0, 0, 0});
	while (!Q.empty())
	{
		P u = Q.top(); Q.pop();
		if (S.find(make_pair(u.x, u.y)) != S.end())
			continue;
		if (u.x == l && u.y == 0)
		{
			printf("%d\n", u.dist - 1);
			break;
		}
		S.insert(make_pair(u.x, u.y));
		for (int i = 1; i <= 5; i++)
		{
			int d = 5 - i;
			pair<int, int> lim = fuck(v[u.x + i], u.y - d, u.y + d);
			for (int j = lim.first; j < lim.second; j++)
				Q.push({u.x + i, v[u.x + i][j], u.dist + 1});
		}
	}
	return 0;
}

pair<int, int> fuck(const vector<int> &v, int low, int high){
    return make_pair(lower_bound(v.begin(), v.end(), low) - v.begin(), upper_bound(v.begin(), v.end(), high) - v.begin());
}
