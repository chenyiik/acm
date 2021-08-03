#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int maxn = int(1e5) + 5;
int a[maxn], b[maxn];
bool c[maxn];

int main()
{
	int _; scanf("%d", &_);
	while (_--)
	{
		int n; scanf("%d", &n);
		for (int i = 0; i < n; i++)
		{
			scanf("%d", &a[i]);
			b[i] = a[i];
			c[i] = false;
		}
		sort(b, b + n);
		int L_max = b[n / 2 - 1], R_min = b[n / 2];
		//cout << L_max << ' ' << R_min << endl;
		int L_sum = 0, R_sum = 0;
		for (int i  = 0; i < n / 2; i++)
			if (a[i] > L_max)
				L_sum++, c[i] = true;
		for (int i = n / 2; i < n; i++)
			if (a[i] < R_min)
				R_sum++, c[i] = true;
		if (L_sum == R_sum)
			;
		else if (L_sum < R_sum)
		{
			int d = R_sum - L_sum;
			for (int i = n / 2 - 1; i >= 0; i--)
				if (d > 0 && a[i] == L_max)
					c[i] = true, d--;
		}
		else if (L_sum > R_sum)
		{
			int d = L_sum - R_sum;
			for (int i = n / 2; i < n; i++)
				if (d > 0 && a[i] == R_min)
					c[i] = true, d--;
		}
		long long ans = 0;
		int i = 0, j = n / 2;
		while (i < n / 2 && j < n)
		{
			while (i < n / 2 && !c[i]) i++;
			while (j < n && !c[j]) j++;
			if (i < n / 2 && j < n)
				ans += j - i, i++, j++;
		}
		printf("%lld\n", ans);
	}
	return 0;
}
