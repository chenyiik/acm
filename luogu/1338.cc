#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int n = 0;
	long long m = 0;
	cin >> n >> m;
	static int a[50005];
	int l = 0, r = n;
	for (int i = 1; i <= n; i++)
	{
		long long j = n - i - 1, t = j * (j + 1) / 2;
		//cout << t << ' ' << m << endl;
		if (t < m)
		{
			a[--r] = i;
			m -= n - i;
		}
		else
			a[l++] = i;
	}
	for (int i = 0; i < n; i++)
		printf("%d ", a[i]);
	puts("");
	return 0;
}
