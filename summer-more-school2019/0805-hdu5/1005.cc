#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>
#include <set>

using namespace std;

struct P
{
	int vis, last, size;
	int d[30];
};

int ans[30], n, k, t;

struct cmp
{
	bool operator()(const P &a, const P &b) const
	{
		for (int i = 1; i < min(a.size, b.size); i++)
			if (a.d[i] != b.d[i])
				return a.d[i] > b.d[i];
		return a.size > b.size;
	}
};

int main()
{
	scanf("%d", &t);
	while (t--)
	{
		scanf("%d%d", &n, &k);
		priority_queue<P, vector<P>, cmp> Q;
		P p;
		p.size = 2;
		memset(p.d, 0x7f, sizeof(p.d));
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				if (i != j)
				{
					p.vis = (1 << i) | (1 << j);
					p.last = j;
					p.d[1] = j - i;
					Q.push(p);
				}
		while (true)
		{
			P p = Q.top();
			Q.pop();
			ans[p.size] = p.last;
			if (p.size == n && --k == 0)
			{
				ans[n] = p.last;
				for (int i = n - 1; i > 0; i--)
					ans[i] = ans[i + 1] - p.d[i];
				break;
			}
			P q;
			memcpy(q.d, p.d, sizeof(p.d));
			q.size = p.size + 1;
			for (int i = 1; i <= n; i++)
				if (0 == ((1 << i) & p.vis))
				{
					q.vis = p.vis | (1 << i);
					q.d[q.size - 1] = i - p.last;
					q.last = i;
					Q.push(q);
				}
		}
		for (int i = 1; i <= n; i++)
			printf("%d%c", ans[i], " \n"[i == n]);
	}
	return 0;
}
