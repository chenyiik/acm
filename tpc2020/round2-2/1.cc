#include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>

using namespace std;

const int maxn = int(1e5) + 5;
char s[maxn];

int main()
{
	int _; scanf("%d", &_);
	while (_--) {
		scanf("%s", s + 1);
		int len = strlen(s + 1);
		int c0 = 0, c1 = 0;
		for (int i = 1; i <= len; i++)
		{
			if (s[i] == '0') c0++;
			else c1++;
		}
		int p = 0;
		while (++p <= len)
		{
			if (s[p] == '0')
			{
				c0--, c1++;
			}
			else
			{
				c1--, c0++;
			}
			if (len % 2 == 0 && c0 == c1) break;
			else if (len % 2 == 1 && abs(c0 - c1) == 1) break;
		}
		printf("1 %d\n", p); 
	}
	return 0;
}
