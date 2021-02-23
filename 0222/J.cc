#include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>

using namespace std;

typedef long long LL;
const int maxn = int(1e5) + 5, d = 600;
int b[maxn], n, *a = b;

bool check(int n)
{
	if (n < 2)
		return false;
	int m = sqrt(0.5 + n);
	for (int i = 2; i <= m; i++)
		if (n % i == 0)
			return false;
	return true;
}

LL calc(LL &sum, int &p, int q)
{
	static int k = 0;
	sum += LL(q - p) * k;
	while (k < n && a[k] <= q)
		sum += p + q - 2 * a[k++];
	sum -= LL(q - p) * (n - k);
	p = q;
	return check(p) ? sum : 0x7fffffffffffffffLL;
}

void init()
{
	int p = 2, count = 0;
	for (int i = 3; i < int(1e9); i++)
	{
		if (i % int(1e7) == 0)
			cout << i / int(1e7) << endl;
		if (check(i))
		{
			if (i - p > count)
			{
				count = i - p;
				cout << p << ' ' << i << ' ' << count << endl;
			}
			p = i;
		}
	}
}

int main()
{
	//init();
	scanf("%d", &n);
	LL sum = 0;
	for (int i = 0; i < n; i++)
		scanf("%d", &b[i]);
	sort(b, b + n);
	LL ans2 = 0;
	while (n > 1 && a[n - 1] - a[0] > d)
	{
		ans2 += a[n - 1] - a[0];
		a++, n -= 2;
	}
	for (int i = 0; i < n; i++)
		sum += b[i];
	LL ans = sum;
	int p = 0;
	for (int i = 0; i < n; i++)
	{
		if (p >= a[i] + d)
			continue;
		if (a[i] - d > p)
			ans = min(ans, calc(sum, p, a[i] - d));
		while (p < a[i] + d)
			ans = min(ans, calc(sum, p, p + 1));
	}
	printf("%lld\n", ans + ans2);
	return 0;
}
