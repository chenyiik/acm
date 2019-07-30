#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <ctime>
#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>
#include <utility>
#include <queue>
#include <stack>
#include <list>
#include <vector>
#include <set>
#include <map>

using namespace std;

int main()
{
	int n = 0;
	static char s[5000007];
	scanf("%d %s", &n, s);
	int len = strlen(s);
	vector<int> v;
	bool vis[10];
	int h = 0, t = 0, k = 9;
	while (h < len)
	{
		memset(vis, false, sizeof(vis));
		vis[0] = true;
		while (t < len)
		{
			int d = s[t] - '0';
			for (int i = 9; i >= d; i--)
			{
				if (vis[i - d])
					vis[i] = true;
			}
			t++;
			if (vis[k])
			{
				h = t;
				v.push_back(k);
				break;
			}
		}
		if (h < t)
		{
			k--;
			t = h;
		}
	}
	for (int i : v)
		printf("%d", i);
	printf(" %d\n", n - v.size());
	return 0;
}
