#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

bool solve()
{
	int n = 0, k = 0;
	scanf("%d%d", &n, &k);
	static int a[256];
	memset(a, 0, sizeof(a));
	for (int i = 0; i < n; i++)
	{
		int x = 0;
		scanf("%d", &x);
		if (x > n || x < 0)
			return false;
		a[x]++;
	}
	a[k] += a[0];
	for (int i = 1; i <= n; i++)
	{
		if (a[i] == 0)
			return false;
		a[i + k] += a[i] - 1;
	}
	return true;
}

int main()
{
	int t = 0;
	scanf("%d", &t);
	while (t--)
		puts(solve() ? "Jerry" : "Tom");
	return 0;
}
