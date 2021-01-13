#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

int mov[4][4] = {
	{ 1, 0, 0, 2 },
	{ 0, 1, 1, 3 },
	{ 3, 2, 2, 0 },
	{ 2, 3, 3, 1 }
};

int typ[4][4] = {
	{ 0, 1, 3, 2 },
	{ 0, 2, 3, 1 },
	{ 3, 1, 0, 2 },
	{ 3, 2, 0, 1 }
};

int main()
{
	int n, m; scanf("%d%d", &n, &m);
	m = m - 1;
	int mode = 0, x = 0, y = 0;
	while (n > 1)
	{
		n /= 2;
		int k = m / (n * n);
		if (typ[mode][k] & 1) y += n;
		if (typ[mode][k] & 2) x += n;
		mode = mov[mode][k];
		m %= (n * n);
	}
	x = x + 1, y = y + 1;
	printf("%d %d\n", x, y);
	return 0;
}
