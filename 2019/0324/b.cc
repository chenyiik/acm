#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int main()
{
	int n = 0, h = 0;
	scanf("%d%d", &n, &h);
	queue<int> Qf, Qd;
	int l0, r0;
	scanf("%d%d", &l0, &r0);
	Qf.push(l0);
	int ans = h + (r0 - l0);
	for (int i = 1; i < n; i++)
	{
		int l1, r1;
		scanf("%d%d", &l1, &r1);
		int d = l1 - r0;
		if (h <= d)
			ans = max(ans, h + r0 - Qf.front());
		Qd.push(d);
		h -= d;
		while (!Qd.empty() && h <= 0)
		{
			h += Qd.front();
			Qd.pop();
			Qf.pop();
		}
		Qf.push(l1);
		l0 = l1, r0 = r1;
	}
	ans = max(ans, h + r0 - Qf.front());
	printf("%d\n", ans);
	return 0;
}
