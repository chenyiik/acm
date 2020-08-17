#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int t = 0;
	scanf("%d", &t);
	while (t--)
	{
		int n = 0, m = 0;
		scanf("%d%d", &n, &m);
		static bool ac[20];
		memset(ac, false, sizeof(ac));
		static int unac[20];
		memset(unac, 0, sizeof(unac));
		int ti = 0;
		while (m--)
		{
			int prob, hh, mm;
			char st[5];
			scanf("%d%d:%d%s", &prob, &hh, &mm, st);
			if (ac[prob -= 1000])
				continue;
			if (st[0] == 'A')
			{
				ti += unac[prob] * 20 + hh * 60 + mm;
				ac[prob] = true;
			}
			else
				unac[prob]++;
		}
		int sol = 0;
		for (int i = 1; i <= n; i++)
		{
			if (ac[i])
				sol++;
		}
		printf("%d %d\n", sol, ti);
	}
	return 0;
}
