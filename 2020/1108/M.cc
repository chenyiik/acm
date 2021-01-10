#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

const int maxn = int(5e5) + 5;
int a[maxn], c[maxn], p[maxn], q[maxn];

int main()
{
	int n, m; 
	while (~scanf("%d%d", &n, &m))
	{
		c[0] = p[0] = q[n + 1] = 0;
		set<int> S;
		for (int i = 1; i <= n; i++)
		{
			scanf("%d", &a[i]);
			c[i] = c[i - 1] ^ a[i];
			S.insert(a[i]);
		}
		int sum = 0;
		for (int i : S)
			sum ^= i;
		S.clear();
		for (int i = 1; i <= n; i++)
		{
			if (S.find(a[i]) == S.end())
			{
				S.insert(a[i]);
				p[i] = p[i - 1] ^ a[i];
			}
			else
				p[i] = p[i - 1];
		}
		S.clear();
		for (int i = n; i >= 1; i--)
		{
			if (S.find(a[i]) == S.end())
			{
				S.insert(a[i]);
				q[i] = q[i + 1] ^ a[i];
			}
			else
				q[i] = q[i + 1];
		}
		while (m--)
		{
			int l, r; scanf("%d%d", &l, &r);
			printf("%d\n", c[l - 1] ^ c[r] ^ sum ^ p[r] ^ q[l]);
		}
	}
	return 0;
}
