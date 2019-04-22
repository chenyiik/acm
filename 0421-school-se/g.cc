#include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>

using namespace std;

int euler_phi(int n)
{
	int m = (int)sqrt(n + 0.5);
	int ans = n;
	for (int i = 2; i <= m; i++)
		if (n % i == 0)
		{
			ans = ans / i * (i - 1);
			while (n % i == 0)
				n /= i;
		}
	if (n > 1)
		ans = ans / n * (n - 1);
	return ans;
}

int main()
{
	const int n = 300;
	static int a[n];
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	for (int i = 0; i < n; i++)
	{
		int m = a[i] + 1, st = max(1, m - i);
		bool b = true;
		for (int j = 0; j < n; j++)
		{
			if (euler_phi(st + j) != a[j])
			{
				b = false;
				break;
			}
		}
		if (b)
			return printf("%d\n", st), 0;
	}
	puts("yang12138 laji");
	return 0;
}
