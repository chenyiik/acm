#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

int main()
{
	int n = 0;
	cin >> n;
	set<int> S;
	for (int i = 0; i < n; i++)
	{
		int x = 0;
		cin >> x;
		S.insert(x);
	}
	int ans = 0;
	set<int> T;
	for (auto i : S)
	{
		for (auto j : S)
		{
			if (i < j && S.find(i + j) != S.end() && T.find(i + j) == T.end())
			{
				ans++;
				T.insert(i + j);
			}
		}
	}
	cout << ans << endl;
	return 0;
}
