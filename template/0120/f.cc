#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> v[4];

int main()
{
	int n = 0;
	scanf("%d", &n);
	while (n--)
	{
		char st[5];
		int x;
		scanf("%s%d", st, &x);
		if (strcmp(st, "00") == 0)
			v[0].push_back(x);
		else if (strcmp(st, "01") == 0)
			v[1].push_back(x);
		else if (strcmp(st, "10") == 0)
			v[2].push_back(x);
		else if (strcmp(st, "11") == 0)
			v[3].push_back(x);
	}
	for (int i = 1; i < 3; i++)
		sort(v[i].begin(), v[i].end(), [](int a, int b) { return a > b; });
	int ans = 0;
	for (auto i : v[3])
		ans += i;
	int cnt = v[3].size();
	if (v[1].size() < v[2].size())
	{
		//cnt += v[1].size();
		for (int i = 0; i < v[1].size(); i++)
			ans += v[1][i] + v[2][i];
		for (int i = v[1].size(); i < v[2].size(); i++)
			v[0].push_back(v[2][i]);
	}
	else
	{
		for (int i = 0; i < v[2].size(); i++)
			ans += v[1][i] + v[2][i];
		for (int i = v[2].size(); i < v[1].size(); i++)
			v[0].push_back(v[1][i]);
	}
	sort(v[0].begin(), v[0].end(), [](int a, int b) { return a > b; });
	for (int i = 0; i < cnt && i < v[0].size(); i++)
		ans += v[0][i];
	printf("%d\n", ans);
	return 0;
}
