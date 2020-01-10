#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

int a[1005], s[1005];
vector<int> v[1005];

int main()
{
	int n = 0;
	scanf("%d", &n);
	//memset(s, 0, sizeof(s));
	for (int i = 1; i < n; i++)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		if (x > y)
			swap(x, y);
		if (y != n)
			return puts("NO"), 0;
		v[x].push_back(i);
	}
	queue<int> Q;
	for (int i = 1; i < n; i++)
	{
		if (v[i].empty())
			Q.push(i);
		else
		{
			int x = n;
			for (int j = 1; j < v[i].size(); j++)
			{
				if (Q.empty())
					return puts("NO"), 0;
				a[v[i][j]] = x;
				x = s[v[i][j]] = Q.front();
				Q.pop();
			}
			a[v[i][0]] = i, s[v[i][0]] = x;
		}
	}
	puts("YES");
	for (int i = 1; i < n; i++)
		printf("%d %d\n", a[i], s[i]);
	return 0;
}
