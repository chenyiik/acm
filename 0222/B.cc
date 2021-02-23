#include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>

using namespace std;

typedef long long LL;

int main()
{
	LL a, b;
	scanf("%lld%lld", &a, &b);
	queue<LL> F;
	stack<LL> B;
	LL n = min(1e6, sqrt(0.5 + a));
	for (LL i = 1; i <= n; i++)
	{
		if (a % i != 0)
			continue;
		if (i % b == 0)
			F.push(i);
		LL c = a / i;
		if (c == i)
			continue;
		if (c % b == 0)
			B.push(c);
	}
	n = F.size() + B.size();
	while (!F.empty())
	{
		printf("%lld%c", F.front(), " \n"[--n == 0]);
		F.pop();
	}
	while (!B.empty())
	{
		printf("%lld%c", B.top(), " \n"[--n == 0]);
		B.pop();
	}
	return 0;
}
