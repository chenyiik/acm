#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct P
{
	int vis, last, size;
	int d[20];
	bool operator<(const P &o) const
	{
		for (int i = 1; i < 20; i++)
			if (d[i] > o.d[i])
				return true;
		return false;
	}
};

int ans[21];

int main()
{
	int t;
	scanf("%d", &t);
	while (t--)
	{
		int n, k;
		scanf("%d%d", &n, &k);
		priority_queue<P> Q;
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				if (i != j)
				{
					P p;
					p.vis = (1 << i) | (1 << j);
					p.last = j;
					p.size = 2;
					p.d[1] = i - j;
					Q.push(p);
				}
		while (true)
		{
			P p = Q.top();
			Q.pop();
			if (p.size == n && --k == 0)
			{
				ans[n] = p.last;
				for (int i = n - 1; i > 0; i--)
					ans[i] = ans[i + 1] - p.d[i];
				break;
			}
			P q;
			for (int i = 1; i < p.size; i++)
				q.d[i] = p.d[i];
			q.size = p.size + 1;
			for (int i = 1; i <= n; i++)
				if (0 == ((1 << i) & p.vis))
				{
					q.vis = p.vis | (1 << i);
					q.d[p.size] = i - p.last;
					q.last = i;
					Q.push(q);
				}
		}
		for (int i = 1; i <= n; i++)
			printf("%d%c", ans[i], " \n"[i == n]);
	}
	return 0;
}
