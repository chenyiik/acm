#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

typedef long long LL;

const int maxn = int(1e5) + 5;
LL a[maxn], s[maxn];


struct cmp
{
	bool operator()(int i, int j) const { return a[i] < a[j]; }
};

int main()
{
	int t;
	scanf("%d", &t);
	while (t--)
	{
		int n;
		scanf("%d", &n);
		for (int i = 1; i <= n; i++)
		{
			scanf("%lld", &a[i]);
			s[i] = 0;
			s[i / 2]++;
		}
		priority_queue<int, vector<int>, cmp> Q;
		for (int i = n; i > 0 && s[i] == 0; i--)
			Q.push(i);
		LL sum[2] = {0, 0};
		for (int p = 0; !Q.empty(); p ^= 1)
		{
			int i = Q.top();
			Q.pop();
			sum[p] += a[i];
			if (--s[i / 2] == 0)
				Q.push(i / 2);
		}
		printf("%lld %lld\n", sum[0], sum[1]);
	}
	return 0;
}
