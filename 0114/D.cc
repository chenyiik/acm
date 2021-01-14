#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<string> v[16];
int c[16][16];

int main()
{
	int n, m; scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
	{
		v[i].push_back(string(1, '@' + i));
		for (int j = 1; j < i; j++)
			for (int k = 0; k < v[j].size(); k++)
			{
				v[i].push_back(v[j][k] + string(1, '@' + i - j));
				sort(v[i].back().begin(), v[i].back().end());
			}
		sort(v[i].begin(), v[i].end());
		auto p = unique(v[i].begin(), v[i].end());
		v[i].erase(p, v[i].end());
		//cout << i << ": ";
		//for (auto j = v[i].begin(); j != p; j++)
		//	cout << *j << ' ';
		//cout << v[i].size() << endl;
	}
	for (int j = 1; j <= m; j++) c[0][j] = 1;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			c[i][j] = c[i][j - 1] + c[i - 1][j];
	//for (int i = 1; i <= n; i++)
	//{
	//	for (int j = 1; j <= m; j++)
	//		cout << c[i][j] << ' ';
	//	cout << endl;
	//}
	long long ans = 0;
	for (int i = 0; i < v[n].size(); i++)
	{
		const string &s = v[n][i];
		static int t[16];
		memset(t, 0, sizeof(t));
		for (int j = 0; j < s.size(); j++)
			t[s[j] - '@']++;
		long long cnt = 1;
		for (int j = 1; j <= n; j++)
			cnt *= c[t[j]][m];
		ans += cnt;
	}
	printf("%lld\n", ans);
	return 0;
}
