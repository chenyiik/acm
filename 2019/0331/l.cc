#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <queue>
#include <utility>
#include <vector>
#include <functional>

using namespace std;

typedef pair<int, int> P;

int main()
{
	int m, n, w, h;
	scanf("%d%d%d%d", &m, &n, &w, &h);
	const int N = 2005;
	static int a[N];
	queue<P> work, rest;
	priority_queue<P, vector<P>> wait;
	for (int i = 0; i < m; i++)
	{
		scanf("%d", &a[i]);
		wait.push(make_pair(a[i], i));
	}
	vector<int> ans[N];
	for (int i = 1; i <= n; i++)
	{
		int x;
		scanf("%d", &x);
		while (!work.empty() && work.front().first == i)
			work.pop();
		while (!rest.empty() && rest.front().first == i)
		{
			int x = rest.front().second;
			if (a[x] > 0)
				wait.push(make_pair(a[x], x));
			rest.pop();
		}
		while (!wait.empty() && work.size() < x)
		{
			P p = wait.top();
			wait.pop();
			ans[p.second].push_back(i);
			a[p.second] -= w;
			work.push(make_pair(i + w, p.second));
			rest.push(make_pair(i + w + h, p.second));
		}
		if (work.size() < x && wait.empty())
			//break;
			return puts("-1"), 0;
	}
	puts("1");
	auto &v = ans;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < v[i].size(); j++)
			printf("%d%c", v[i][j], " \n"[j + 1 == v[i].size()]);
	}
	return 0;
}
