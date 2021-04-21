#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool check(vector<int> &u, vector<int> &v)
{
	sort(u.begin(), u.end());
	sort(v.begin(), v.end());
	for (int i = 0; i < v.size(); i++)
	{
		if (u[i] > v[i])
			return false;
		if (i + 1 < u.size() && v[i] > u[i + 1])
			return false;
	}
	return true;
}

int main()
{
	int T; scanf("%d", &T);
	while (T--)
	{
		int n; scanf("%d", &n);
		vector<int> v[2];
		for (int i = 0; i < n; i++)
		{
			int x; scanf("%d", &x);
			v[i % 2].push_back(x);
		}
		if (n % 2 == 1)
		{
			puts("Yes");
			continue;
		}
		puts(check(v[0], v[1]) ? "Yes" : "No");
	}
	return 0;
}
