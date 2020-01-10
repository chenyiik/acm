#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

const int maxn = static_cast<int>(1e6) + 7;
char st[maxn];
long long d[maxn];

int main()
{
	int n = 0;
	scanf("%d", &n);
	scanf("%s", st + 1);
	int l = 0;
	long long x = 0, y = 0;
	set<long long> S;
	S.insert(d[0] = 0);
	int ans = 0;
	for (int i = 1; i <= n; i++)
	{
		if (st[i] == 'R')
			x++;
		else if (st[i] == 'L')
			x--;
		else if (st[i] == 'U')
			y++;
		else if (st[i] == 'D')
			y--;
		d[i] = x * maxn + y;
		auto it = S.find(d[i]);
		if (it == S.end())
		{
			S.insert(d[i]);
			ans = max(ans, i - l);
		}
		else
		{
			ans = max(ans , i - l - 1);
			while (1)
			{
				auto jt = S.find(d[l++]);
				if (jt == it)
					break;
				else
					S.erase(jt);
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}
