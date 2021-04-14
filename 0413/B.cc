#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

int a[1010];

int solve(int n)
{
	int flag = 0;
	for (int i = 1; i <= 1000; i++)
	{
		if (a[i] == 0)
			continue;
		if (a[i] > 2)
			return 0;
		if (a[i] == 2)
		{
			if (flag == 0)
				flag = i;
			else
				return 0;
		}
	}
	if (flag > 0)
	{
		for (int i = 1; i < flag; i++)
		{
			if (a[i] == 0 && a[flag - i] == 0 && i != flag - i)
				return 2;
		}
		return 0;
	}
	int ans = 0;
	for (int i = 1; i <= 1000; i++)
	{
		if (a[i] == 1)
		{
			int key = 0;
			for (int j = 1; j < i; j++)
			{
				if (a[j] == 0 && a[i - j] == 0 && j != i - j)
				{
					//cout << i << ' ' << j << ' ' << i - j << endl;
					key = 1;
					break;
				}
			}
			ans += key;
		}
	}
	return ans;
}

int main()
{
	int T; scanf("%d", &T);
	while (T--)
	{
		int n; scanf("%d", &n);
		memset(a, 0, sizeof(a));
		for (int i = 0; i < n; i++)
		{
			int x; scanf("%d", &x);
			a[x]++;
		}
		printf("%d\n", solve(n));
	}
	return 0;
}
