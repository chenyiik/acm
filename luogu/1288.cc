#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

int a[25];

int main()
{
	int n = 0;
	scanf("%d", &n);
	bool zero = false;
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
		if (a[i] == 0)
			zero = true;
	}
	if (zero)
	{
		int s = 0, r = n - 1;
		while (a[s] != 0)
			s++;
		while (a[r] != 0)
			r--;
		puts(s % 2 == 1 || (n - 1 - r) % 2 == 1 ? "YES" : "NO");
	}
	else
	{
		if (n % 2 == 1)
			puts("YES");
		else
		{
			int s = 0, r = n - 1;
			while (a[s] != 1)
				s++;
			while (a[r] != 1)
				r--;
			puts(s % 2 == 1 || (n - 1 - r) % 2 == 1 ? "YES" : "NO");
		}
	}
	return 0;
}
