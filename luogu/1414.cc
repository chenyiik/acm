#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int maxN = static_cast<int>(1e6) + 7;
int a[maxN], s[maxN];


int main()
{
	int n = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		int x = 0;
		scanf("%d", &x);
		a[x]++;
	}
	for (int i = 1; i <= maxN - 7; i++)
	{
		int d = 0;
		for (int j = i; j <= maxN - 7; j += i)
			d += a[j];
		s[d] = i;
	}
	int e = 0;
	for (int i = n; i > 0; i--)
		e = s[i] = max(s[i], e);
	for (int i = 1; i <= n; i++)
		printf("%d\n", s[i]);
	return 0;
}
