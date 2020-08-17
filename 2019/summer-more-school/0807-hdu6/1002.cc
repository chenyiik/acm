#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <stack>

using namespace std;

const int maxn = int(5e4) + 5, oo = 0x7fffffff;
int A[maxn], b[maxn], d[maxn], g[maxn], id[maxn], gg[maxn];
bool u[maxn];
int pre[maxn];

int find(int n, int x)
{
	//cout << endl << x << endl;
	gg[0] = -1;
	for (int i = 1; i <= n + 1; i++) g[i] = +oo;
	memset(pre, -1, sizeof(pre));
	for (int i = 0; i < n; i++) if (b[i] <= x)
	{
		int k = lower_bound(g + 1, g + n + 1, A[i]) - g;
		d[i] = k;
		g[k] = A[i], gg[k] = i;
		pre[i] = gg[k - 1];
		//cout << k << ' ' << pre[i] << endl;
	}
	//for (int i = 0; i < n; i++)
		//cout << A[i] << ' ' << g[i] << ' ' << gg[i] << ' ' << pre[i] << endl;
	memset(u, false, sizeof(u));
	for (int i = 2; i <= n + 1; i++)
		if (g[i] == +oo)
		{
			int j = gg[--i];
			while (j > -1)
				/*cout << j << endl, */u[j] = true, j = pre[j];
			return i;
		}
}

int main()
{
	int _; scanf("%d", &_);
	while (_--)
	{
		int n; scanf("%d", &n);
		for (int i = 0; i < n; i++)
		{
			scanf("%d", &A[i]);
			id[i] = i;
		}
		for (int i = 0; i < n; i++)
		{
			int x; scanf("%d", &x);
			b[x - 1] = i + 1;
		}
		sort(id, id + n, [](int x,int y){return b[x] > b[y];});
		stack<int> S;
		int ans = -1;
		for (int i = n, j = -1; i > 0; i--, j++)
		{
			//cout << endl << id[j] << (u[id[j]] ? "true" : "false") << endl;
			if (ans != -1 && !u[id[j]])
				S.push(ans);
			else
				S.push(ans = find(n, i));
		}
		while (!S.empty())
			printf("%d%c", S.top(), " \n"[S.size() == 1]), S.pop();
	}
	return 0;
}
