#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <deque>

using namespace std;

struct P
{
	int value, id;
};

const int maxn = int(1e5) + 5;
int a[maxn];

int main()
{
	int T; scanf("%d", &T);
	while (T--)
	{
		int n; scanf("%d", &n);
		for (int i = 0; i < n; i++)
			scanf("%d", &a[i]);
		deque<P> S, T;
		int l = 0, ans = 1;
		S.push_back({a[0], 0}), T.push_back({a[0], 0});
		for (int r = 1; r < n; r++)
		{
			while (l < r && (a[r] % S.front().value != 0 && S.front().value % a[r] != 0 || T.front().value % a[r] != 0 && a[r] % T.front().value != 0))
			{
				if (!S.empty() && S.front().id == l)
					S.pop_front();
				if (!T.empty() && T.front().id == l)
					T.pop_front();
				l++;
			}
			while (!S.empty() && a[r] >= S.back().value)
				S.pop_back();
			S.push_back({a[r], r});
			while (!T.empty() && a[r] <= T.back().value)
				T.pop_back();
			T.push_back({a[r], r});
			ans = max(ans, r - l + 1);
		}
		printf("%d\n", ans);
	}
	return 0;
}
