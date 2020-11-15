#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int maxn = int(3e4) + 5;
int a[maxn], b[maxn], c[maxn];

bool check(int n)
{
	int k = int(1e6) + 5, i;
	for (i = 0; i < n; i++)
	{
		if (k >= a[i])
			k = a[i], a[i] = 0;
		else
		{
			a[i] -= k;
			break;
		}
	}
	int t = a[i];
	for (i = i + 1; i < n; i++)
	{
		//cout << k << ' ' << t << endl;
		if (t > a[i])
			return false;
		a[i] -= t, k = min(k, a[i]), a[i] -= k, t += a[i];
	}
	return true;
}

int main()
{
	int _; scanf("%d", &_);
	while (_--)
	{
		int n; scanf("%d", &n);
		for (int i = 0; i < n; i++)
			scanf("%d", &a[i]);
		puts(check(n) ? "YES" : "NO");
	}
	return 0;
}
