#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

const int maxn = 2005;
int a[maxn];

struct R { int tot, last; };

int main()
{
	int t;
	scanf("%d", &t);
	while (t--)
	{
		int n, k;
		scanf("%d%d", &n, &k);
		for (int i = 1; i <= n; i++)
			scanf("%d", &a[i]);
		priority_queue<R> PP, QQ, *P = &PP, *Q = &QQ;
		P->push(R{0, 0});
		for (int i = 1; i <= n; i++, swap(P, Q))
		{
		}
 	}
	return 0;
}
