#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

const int maxn = 1005;
int b[maxn];

bool f(int n)
{
	set<int> S;
	for (int i = 0; i < n; i++)
	{
		if (S.find(b[i]) != S.end())
			return true;
		else
			S.insert(b[i]);
	}
	return false;
}

int main()
{
	int t; scanf("%d", &t);
	while (t--)
	{
		int n; scanf("%d", &n);
		for (int i = 0; i < n; i++)
			scanf("%d", &b[i]);
		puts(f(n) ? "YES" : "NO");
	}
	return 0;
}
