#include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <map>
#include <stack>

using namespace std;

typedef long long LL;

map<LL, LL> M;

void dfs(LL n, LL fa)
{
	if (M.find(n) != M.end())
		return;
	M[n] = fa;
	for (LL p = 10; p <= n; p *= 10)
	{
		LL a = n / p, b = n % p;
		if (a != b)
			dfs(abs(a - b), n);
	}
}

int main()
{
	int t; scanf("%d", &t);
	while (t--)
	{
		LL n; scanf("%lld", &n);
		M.clear();
		dfs(n, -1);
		stack<LL> S;
		for (auto i = M.begin(); i != M.end(); i = M.find(i->second))
			S.push(i->first);
		printf("%lu ", S.size());
		while (!S.empty())
			printf("%lld%c", S.top(), " \n"[S.size() == 1]), S.pop();
	}
	return 0;
}
