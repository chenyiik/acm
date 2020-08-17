#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int maxn = int(2e5) + 5;
int a[maxn];

int main()
{
	int n;
	scanf("%d", &n);
	int index = 0;
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
		if (a[i] > a[index])
			index = i;
	}
	int L = index - 1, R = index + 1, ths = n - 1;
	while (L != 0 || R != n + 1)
	{
		if (a[L] == ths)
			ths--, L--;
		else if (a[R] == ths)
			ths--, R++;
		else
			return puts("NO"), 0;
	}
	puts("YES");
	return 0;
}
