#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int maxn = int(1e6) + 5;
int a[maxn], f[maxn];

int main()
{
	int n; scanf("%d", &n);
	for (int i = n - 1; i >= 0; i--)
		scanf("%d", &a[i]);
	for (int i = 1; i < n; i++)
	{
		int j = f[i];
		while (j && a[i] != a[j])
			j = f[j];
		f[i + 1] = a[i] == a[j] ? j + 1 : 0;
	}
	int k = n - 1, p = 1;
	for (int i = 2; i <= n; i++)
	{
		if (n - f[i] < k + p || (n - f[i] == k + p && i - f[i] < p))
			k = n - i, p = i - f[i];
	}
	printf("%d %d\n", k, p);
	return 0;
}
