#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>

using namespace std;

typedef long long LL;

int mp[55];
LL tot = 0;

void sayno() { puts("No"); exit(0); }

void dfs(int n, int L, int R)
{
	if (n == 0)
		return;
	int mid = 0 ^ 1 ^ 2 ^ L ^ R;
	if (mp[n] == mid)
		sayno();
	else if (mp[n] == L)
		dfs(n - 1, L, mid);
	else if (mp[n] == R)
	{
		tot += 1LL << (n - 1);
		dfs(n - 1, mid, R);
	}
}

int main()
{
	int n = 0;
	for (int i = 0; i < 3; i++)
	{
		int k, y = 51, x; scanf("%d", &k);
		while (k--)
		{
			scanf("%d", &x);
			mp[x] = i;
			n = max(n, x);
			if (x < y)
				y = x;
			else
				sayno();
		}
	}
	dfs(n, 0, 2);
	LL sum = (1LL << n) - 1;
	printf("%lld\n", sum - tot);
	return 0;
}
