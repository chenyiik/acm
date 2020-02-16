#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int maxn = int(1e5) + 7;
int f[maxn];

void init(int n)
{
	for (int i = 1; i <= n; i++)
		f[i] = i;
}

int find_father(int x)
{
	if (f[x] == x)
		return x;
	else
		return f[x] = find_father(f[x]);
}

void connet(int x, int y)
{
	int f1 = find_father(x), f2 = find_father(y);
	f[f2] = f1;
}

bool is_same_father(int x, int y)
{
	return find_father(x) == find_father(y);
}

int main()
{
	int t; scanf("%d", &t);
	while (t--)
	{
		int n, m, q; scanf("%d%d%d", &n, &m, &q);
		init(n);
		while (m--)
		{
			int x, y; scanf("%d%d", &x, &y);
			connet(x, y);
		}
		while (q--)
		{
			int x, y; scanf("%d%d", &x, &y);
			putchar(is_same_father(x, y) ? '1' : '0');
		}
		puts("");
	}
	return 0;
}
