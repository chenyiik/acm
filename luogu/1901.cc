#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <stack>

using namespace std;

int main()
{
	int n = 0;
	scanf("%d", &n);
	const int maxn = (int)1e6 + 10;
	static long long h[maxn], x[maxn], v[maxn];
	for (int i = 1; i <= n; i++)
		scanf("%lld%lld", &h[i], &x[i]);
	stack<int> S;
	for (int i = 1; i <= n; i++)
	{
		while (!S.empty() && h[S.top()] < h[i])
			v[i] += x[S.top()], S.pop();
		S.push(i);
	}
	stack<int>().swap(S);
	for (int i = n; i >= 1; i--)
	{
		while (!S.empty() && h[S.top()] < h[i])
			v[i] += x[S.top()], S.pop();
		S.push(i);
	}
	long long ans = 0;
	for (int i = 1; i <= n; i++)
		ans = max(ans, v[i]);
	printf("%lld\n", ans);
	return 0;
}
