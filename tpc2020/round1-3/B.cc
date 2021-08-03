#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int maxn = int(1e5) + 5;
char s[maxn];

int main()
{
	int _; scanf("%d", &_);
	while (_--)
	{
		scanf("%s", s);
		int n = strlen(s), zero = 0, one = 0;
		for (int i = 0; i < n; i++)
			if (s[i] == '0') zero++;
			else one++;
		bool flag = true;
		if (zero % 2 == 0)
		{
			for (int i = 0; i < n; i++)
			{
				if (zero && i % 3 != 2) zero--, s[i] = '0';
				else if (one) one--, s[i] = '1';
				else { flag = false; break; }
			}
		}
		else
		{
			zero--, s[0] = '0';
			if (one)
			{
				one--, s[1] = '1';
				for (int i = 2; i < n; i++)
				{
					if (zero && i % 3 != 1) zero--, s[i] = '0';
					else if (one) one--, s[i] = '1';
					else { flag = false; break; }
				}
			}
			else flag = false;
		}
		if (flag)
		{
			for (int i = n - 1; i >= 0; i--)
				putchar(s[i]);
			puts("");
		}
		else
			puts("Impossible");
	}
	return 0;
}
