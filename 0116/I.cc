#include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <queue>

using namespace std;

typedef long long LL;

struct P { LL nxt, ans; };
unordered_map<LL, P> M;

LL dfs(LL n)
{
	auto it = M.find(n);
	if (it != M.end()) 
		return it->second.ans;
	M[n] = {-1, n};
	for (LL p = 10; p <= n; p *= 10)
	{
		LL a = n / p, b = n % p;
		if (a == b) continue;
		LL c = abs(a - b);
		LL d = dfs(c);
		if (d < M[n].ans)
			M[n] = {c, d};
	}
	return M[n].ans;
}

int main()
{
	int t; scanf("%d", &t);
	while (t--)
	{
		LL n; scanf("%lld", &n);
		dfs(n);
		queue<LL> Q;
		for (auto i = M.find(n); i != M.end(); i = M.find(i->second.nxt))
			Q.push(i->first);
		printf("%lu ", Q.size());
		while (!Q.empty())
			printf("%lld%c", Q.front(), " \n"[Q.size() == 1]), Q.pop();
	}
	return 0;
}
