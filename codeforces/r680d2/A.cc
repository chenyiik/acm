#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int maxn = 105;
int a[maxn], b[maxn];

bool check(int n, int x)
{
	for (int i = 0; i < n; i++)
	{
		int j = n - i - 1;
		if (a[i] + b[j] > x)
			return false;
	}
	return true;
}

int main()
{
	int _; scanf("%d", &_);
	while (_--)
	{
		int n, x; scanf("%d%d", &n, &x);
		for (int i = 0; i < n; i++)
			scanf("%d", &a[i]);
		for (int i = 0; i < n; i++)
			scanf("%d", &b[i]);
		sort(a, a + n);
		sort(b, b + n);
		puts(check(n, x) ? "Yes" : "No");
	}
	return 0;
}
