#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

bool g(int a[], int m, int k)
{
	int r = 0;
	for (int i = 0; i < m; i++)
	{
		if (a[i] == 1)
			r++;
	}
	//cout << r << endl;
	if (r <= k)
		return puts("0"), true;
	else
		return false;
}

long long f(int a[], int n)
{
	int s = 0;
	for (int i = 0, j = 1; i < n; i++, j *= 2)
		s += a[i] == 1 ? j : 0;
	for (long long i = 1; ; i *= 2)
	{
		if (i > s)
			return i - s;
	}
}

int main()
{
	int n = 0, k = 0;
	cin >> n >> k;
	int a[40], m = 0;
	while (n > 0)
	{
		a[m++] = n % 2;
		n /= 2;
	}
	//for (int i = 0; i < 10; i++)
		//cout << a[i] << ' ';
	//cout << endl;
	if (g(a, m, k))
		return 0;
	for (int i = m - 1; i >= 0; i--)
	{
		if (k == 1)
			return printf("%lld\n", f(a, i + 1)), 0;
		if (a[i] == 1)
			k--;
	}
}
