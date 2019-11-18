#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int maxn = int(1e5) + 5;
int a[maxn];

int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	sort(a, a + n);
	int b = -1;
	for (int i = 1; i < n; i++)
	{
		if (a[i] == a[i - 1])
		{
			if (b == -1)
				b = i;
			else 
			{
				puts("cslnb");
				return 0;
			}
		}
	}
	if (b != -1 && b > 1 && a[b - 1] == a[b - 2] + 1)
	{
		puts("cslnb");
		return 0;
	}
	if (a[0] == 0 && a[1] == 0)
	{
		puts("cslnb");
		return 0;
	}
	long long tot = 0;
	for (int i = 0; i < n; i++)
		tot += a[i] - i;
	puts(tot % 2 == 1 ? "sjfnb" : "cslnb");
	return 0;
}
