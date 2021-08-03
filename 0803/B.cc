#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

const int cn = 60000;
long long c[cn + 5];

map<int, pair<int, int>> M;
void init()
{
	c[0] = 1;
	M[1] = make_pair(0, 0);
	int r = 100;
	for (int i = 0; i <= cn; i++)
	{
		for (int j = min(i / 2, r); j > 0; j--)
		{
			if (i % 2 == 0 && j * 2 == i)
				c[j] = c[j - 1] * 2;
			else
				c[j] = c[j - 1] + c[j];
			if (c[j] >= int(1e9))
				r = j - 1;
			else
			{
				map<int, pair<int, int>>::iterator it = M.find(c[j]);
				if (it == M.end())
					M[c[j]] = make_pair(i, j);
				else
				{
					pair<int, int> d = it->second;
					if (i + j < d.first + d.second || i + j == d.first + d.second && i < d.first)
						M[c[j]] = make_pair(i, j);
				}
			}
		}
		if (r == 1)
			break;
	}
}

int main()
{
	init();
	int _; scanf("%d", &_);
	while (_--)
	{
		int x; scanf("%d", &x);
		map<int, pair<int, int>>::iterator it = M.find(x);
		if (it == M.end())
		{
			printf("%d %d\n", x, 1);
		}
		else
		{
			pair<int, int> d = it->second;
			printf("%d %d\n", d.first, d.second);
		}
	}
	return 0;
}
