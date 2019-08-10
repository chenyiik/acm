#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <stack>

using namespace std;

const int maxn = 3005;
char s[maxn];
int tag[maxn][maxn];
int a[maxn][maxn];

struct P { int id, val; };

int main()
{
	int n, m;
	scanf("%d%d", &n, &m);
	long long ans = 0;
	for (int i = 1; i <= n; i++)
	{
		scanf("%s", s);
		for (int j = 0; j < m; j++)
			a[i][j] = s[j] == '1' ? a[i - 1][j] + 1 : 0;
	}
	for (int i = 1; i <= n; i++)
	{
		stack<P> S;
		S.push({0, 0});
		for (int j = 0; j <= m; j++)
		{
			if (a[i][j] == S.top().val)
				;
			else if (a[i][j] > S.top().val)
				S.push({j, a[i][j]});
			else
			{
				int id;
				while (a[i][j] < S.top().val)
				{
					id = S.top().id;
					tag[i][id] = j - id;
					if (tag[i][id] != tag[i - 1][id])
						;//ans++;
					S.pop();
				}
				if (a[i][j] != S.top().val)
					S.push({id, a[i][j]});
			}
		}
		for (int j = 0; j <= m; j++)
			cout << tag[i][j] << ' ';
		cout << endl;
	}
	for (int i = 0; i < m; i++)
	{
		cout << ans << endl;
		stack<int> S;
		S.push(0);
		for (int j = 1; j <= n + 1; j++)
		{
			if (tag[j][i] == S.top())
				;
			else if (tag[j][i] > S.top())
				ans++, S.push(tag[j][i]);
			else
			{
				while (tag[j][i] < S.top())
					S.pop();
				if (S.top() == 0)
					ans++;
				S.push(tag[j][i]);
			}
		}
	}
	printf("%lld\n", ans);
	return 0;
}
