#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int maxn = int(2e5) + 5;
int a[maxn], b[2][maxn], n;

int f(const int a[])
{
	int ret = 0x7fffffff;
	for (int i = 1; i < n; i++)
		ret = min(ret, abs(a[i - 1] - a[i]));
	return ret;
}

void show(const int a[])
{
	//cout << f(a) << endl;
	for (int i = 0; i < n; i++)
		printf("%d%c", a[i], " \n"[i + 1 == n]);
}


int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	sort(a, a + n);
	if (n % 2 == 0)
	{
		int m = n / 2;
		for (int i = 0; i < n; i++)
		{
			b[0][i] = a[i / 2 + (i % 2) * m];
			b[1][i] = a[i / 2 + (i % 2 ^ 1) * m];
		}
	}
	else
	{
		int m = n / 2;
		for (int i = 0; i < n; i++)
			b[0][i] = a[i / 2 + (i % 2 ^ 1) * m];
		m++;
		for (int i = 0; i < n; i++)
			b[1][i] = a[i / 2 + (i % 2) * m];
	}
	if (f(b[0]) >= f(b[1]))
		show(b[0]);
	else
		show (b[1]);
	return 0;
}
