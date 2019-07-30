#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

bool b[1007];

void init(int l, int r)
{
	for (int i = l; i <= r; i++)
	{
		int n = i;
		int a0 = n % 10;
		n /= 10;
		int a1 = n % 10;
		n /= 10;
		int a2 = n;
		b[i] = i == a0 * a0 * a0 + a1 * a1 * a1 + a2 * a2 * a2;
	}
}

int main()
{
	init(100, 999);
	int l = 0, r = 0;
	while (~scanf("%d%d", &l, &r))
	{
		int tot = 0;
		for (int i = l; i <= r; i++)
		{
			if (b[i])
			{
				if (tot++)
					printf(" ");
				printf("%d", i);
			}
		}
		if (tot)
			printf("\n");
		else
			printf("no\n");
	}
	return 0;
}
