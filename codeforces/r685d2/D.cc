#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>

using namespace std;

int main()
{
	int T; scanf("%d", &T);
	while (T--)
	{
		int d, k; scanf("%d%d", &d, &k);
		vector<pair<int, int>> v;
		int count = 0;
		for (int i = 0, j = d; i <= j; i++)
		{
			while (i * i + j * j > d * d) j--;
			if (i > j) break;
			count = max(count, i / k + j / k);
			//v.push_back(make_pair(i, j));
		}
		puts(count % 2 == 1 ? "Ashish" : "Utkarsh");
		/*
		for (int i = 1; i < v.size(); i++)
		{
			if (v[i].second / k < v[i - 1].second / k)
			{
				int x = v[i - 1].first / k, y = v[i - 1].second / k;
				cout << x << ' ' << y << ' ' << x + y << endl;
			}
			if (i + 1 == v.size())
			{
				int x = v[i].first / k, y = v[i].second / k;
				cout << x << ' ' << y << ' ' << x + y << endl;
			}
		}
		*/
	}
	return 0;
}
