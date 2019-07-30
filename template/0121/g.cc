#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int t = 0;
	scanf("%d", &t);
	while (t--)
	{
		int n = 0;
		scanf("%d", &n);
		int a[7];
		int sum = 0;
		for (int &i : a)
		{
			scanf("%d", &i);
			sum += i;
		}
		int week = n / sum;
		int r = n % sum;
		if (r == 0)
		{
			week -= 1;
			r += sum;
		}
		int ans = week * 7;
		int mint = 10;
		for (int i = 0; i < 7; i++)
		{
			if (a[i] == 0)
				continue;
			int tot = 0;
			for (int j = i, t = r; t; j = (++j % 7), tot++)
			{
				if (a[j] == 0)
					continue;
				t--;
			}
			mint = min(mint, tot);
		}
		ans += mint;
		printf("%d\n", ans);
	}
	return 0;
}
