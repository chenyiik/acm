#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int maxn = (int)3e5 + 7;
int C[maxn];

int lowbit(int x) { return x & -x; }

int sum(int x)
{
	x++;
	int ret = 0;
	while (x > 0)
	{
		ret += C[x];
		x -= lowbit(x);
	}
	return ret;
}

void add(int x, int d)
{
	x++;
	while (x <= maxn)
	{
		C[x] += d;
		x += lowbit(x);
	}
}

bool able(int x) { return x == 0 ? sum(x) : sum(x) - sum(x - 1); } 

int a[maxn], n, b;

int f()
{
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
		if (able(a[i]))
			add(a[i], -1);
		else
			return i;
	}
	add(a[n], 1);
	return n;
}

int g(int ri)
{
	for (int i = ri; i >= 1; i--)
	{
		int r = sum(b - 1);
		int s = r - sum(a[i]);
		int t = n - i + 1;
		if (s >= 1 && r >= t)
			return i;
		if (i > 1)
			add(a[i - 1], 1);
	}
	return 0;
}

int main()
{
	scanf("%d%d", &n, &b);
	for (int i = 0; i < b; i++)
		add(i, 1);
	int pos = f();
	pos = g(pos);
	for (int i = a[pos] + 1; i < b; i++)
	{
		if (able(i))
		{
			a[pos] = i;
			add(i, -1);
			break;
		}
	}
	for (int i = pos + 1, j = 0; i <= n; i++)
	{
		while (!able(j))
			j++;
		a[i] = j;
		add(j, -1);
	}
	int star = pos == 0 ? 0 : 1;
	for (int i = star; i <= n; i++)
		printf("%d%c", a[i], " \n"[i == n]);
	return 0;
}
