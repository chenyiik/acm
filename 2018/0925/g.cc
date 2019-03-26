#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

double f[1007];

void init(int n)
{
	f[0] = 0.0;
	for (int i = 1; i < n; i++)
		f[i] = f[i - 1] + 1.0 / i * (i % 2 == 1 ? 1 : -1);
}

int main()
{
	init(1003);
	int t = 0;
	scanf("%d", &t);
	while (t--)
	{
		int n = 0;
		scanf("%d", &n);
		printf("%.2f\n", f[n]);
	}
	return 0;
}
