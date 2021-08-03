#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <stack>

using namespace std;

const int maxn = int(1e5) + 5;
int a[maxn];

bool solve()
{
	int n; scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%d", &a[i]);
	stack<int> S; S.push(a[0]);
	for (int i = 1; i < n; i++)
	{
		while (!S.empty() && S.top() >= a[i])
			if (S.top() % a[i] == 0) S.pop();
			else return false;
		if (S.empty() || a[i] % S.top() == 0) S.push(a[i]);
		else return false;
	}
	return true;
}

int main()
{
	int _; scanf("%d", &_);
	while (_--)
		puts(solve() ? "Yes" : "No");
	return 0;
}
