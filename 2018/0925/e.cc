#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

long long f[60];

void init(int n)
{
	f[0] = 0, f[1] = 1;
	for (int i = 2; i < n; i++)
		f[i] = f[i - 1] + f[i - 2];
}

int main()
{
	init(55);
	int n = 0;
	while (~scanf("%d", &n) && n != -1)
		printf("%lld\n", f[n]);
	return 0;
}
