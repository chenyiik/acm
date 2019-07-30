#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

long long f[50];

void init(int n)
{
	f[0] = 0, f[1] = 1;
	for (int i = 2; i < n; i++)
		f[i] = f[i - 1] + f[i - 2];
}

int main()
{
	init(45);
	int t = 0;
	scanf("%d", &t);
	while (t--)
	{
		int n = 0;
		scanf("%d", &n);
		printf("%lld\n", f[n]);
	}
	return 0;
}
