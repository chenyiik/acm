#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

int f[105][105][5];
long double p[105];

void init()
{
	p[0] = 1.0;
	for (int i = 1; i <= 103; i++)
		p[i] = p[i - 1] * 2 / 3;
}

int main()
{
	init();
	int n = 0, m = 0;
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
	{
		int x = 0;
		scanf("%d", &x);
		for (int j = 0; j <= 103; j++)
			
	}
	return 0;
}
