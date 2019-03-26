#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

int f[60];

void init(int n)
{
	for (int i = 1; i <= 4; i++)
		f[i] = i;
	for (int i = 5; i <= n; i++)
		f[i] = f[i - 1] + f[i - 3];
}

int main()
{
	init(55);
	int n = 0;
	while (~scanf("%d", &n) && n)
		printf("%d\n", f[n]);
	return 0;
}
