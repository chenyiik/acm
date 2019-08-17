#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

typedef long long LL;

LL len[100];

void init()
{
	len[1] = 6, len[2] = 7;
	for (int i = 3; i < 60; i++)
		len[i] = len[i - 1] + len[i - 2];
}

int main()
{
	init();
	int _; scanf("%d", &_);
	while (_--)
	{
		int n; long long k; scanf("%d%lld", &n, &k);
		while (n > 60)
			n -= 2;
		int tag = 0;
		while (n > 4)
		{
			if (len[n - 2] < k)
				k -= len[n - 2], n = n - 1;
			else
				tag = n - 1, n = n - 2;
		}
		while (tag > 4)
			tag -= 2;
		static const char s[5][50] = {"\0\0\0\0\0\0\0\0\0\0\0", "COFFEE\0\0\0\0\0\0\0\0\0\0\0\0", "CHICKEN\0\0\0\0\0\0\0\0\0\0\0\0", "COFFEECHICKEN\0\0\0\0\0\0\0\0\0\0\0\0", "CHICKENCOFFEECHICKEN\0\0\0\0\0\0\0\0\0\0\0\0"};
		int l = strlen(s[n] + k - 1);
		if (l >= 10)
		{
			for (int i = k - 1; i < k - 1 + 10; i++)
				printf("%c", s[n][i]);
		}
		else
		{
			printf("%s", &s[n][k - 1]), l = 10 - l;
			for (int i = 0; s[tag][i] && i < l; i++)
				printf("%c", s[tag][i]);
		}
		puts("");
	}
	return 0;
}
