#include <cstdio>
#include <cstring>
#include <ctime>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <algorithm>

using namespace std;

int gcd(int a, int b) { return !b ? a : gcd(b, a % b); }

struct P { int x, y; };

int main()
{
	static P a[static_cast<int>(1e5) + 7];
	int n = 0, p = 0;
	scanf("%d%d", &n, &p);
	if (n == 1)
	{
		puts("possible");
		return 0;
	}
	for (int i = 0; i < n; i++)
		scanf("%d%d", &a[i].x, &a[i].y);
	srand(time(0));
	int ttt = time(0);
	while (time(0) - ttt <= 3)
	{
		//int id0 = abs(((rand() << 16) | rand()) % n);
		//int id1 = abs(((rand() << 16) | rand()) % n);
		int id0 = rand() % n;
		int id1 = rand() % n;
		if (id0 == id1)
			continue;
		int noK = 2;
		if (a[id0].x == a[id1].x)
		{
			for (int i = 0; i < n; i++)
			{
				if (i == id0 || i == id1)
					continue;
				if (a[i].x == a[id0].x)
					noK++;
			}
		}
		else if (a[id0].y == a[id1].y)
		{
			for (int i = 0; i < n; i++)
			{
				if (i == id0 || i == id1)
					continue;
				if (a[i].y == a[id0].y)
					noK++;
			}
		}
		else
		{
			int aaa = abs(a[id1].y - a[id0].y), bbb = abs(a[id1].x - a[id0].x);
			int ccc = gcd(aaa, bbb);
			aaa /= ccc, bbb /= ccc;
			for (int i = 0; i < n; i++)
			{
				if (i == id0 || i == id1)
					continue;
				if (a[i].x == a[id0].x || a[i].y == a[id0].y)
					continue;
				int att = abs(a[i].y - a[id0].y), btt = abs(a[i].x - a[id0].x);
				int ctt = gcd(att, btt);
				att /= ctt, btt /= ctt;
				if (aaa == att && bbb == btt)
					noK++;
			}
		}
		if (noK * 100 >= n * p)
		{
			puts("possible");
			return 0;
		}
	}
	puts("impossible");
	return 0;
}
