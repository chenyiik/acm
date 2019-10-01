#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <stack>

using namespace std;

long long one[30], two[30];

int main()
{
	int t;
	scanf("%d", &t);
	while (t--)
	{
		long long n;
		scanf("%lld", &n);
		if (n % 3 == 0)
			printf("1 %lld\n", n);
		else if (n % 3 == 1)
		{
			int oN = 0, tN = 0;
			for (long long i = 1; i > 0; i <<= 1)
				if (n & i)
				{
					if (i % 3 == 1)
						one[oN++] = i;
					else
						two[tN++] = i;
				}
			if (oN > 1)
				printf("2 %lld %lld\n", n - one[0], n - one[1]);
			else if (oN > 0)
				printf("2 %lld %lld\n", n - one[0], two[0] + one[0]);
			else
				printf("2 %lld %lld\n", n - two[0] - two[1], two[0] + two[1] + two[2]);
		}
		else if (n % 3 == 2)
		{
			int oN = 0, tN = 0;
			for (long long i = 1; i > 0; i <<= 1)
				if (n & i)
				{
					if (i % 3 == 1)
						one[oN++] = i;
					else
						two[tN++] = i;
				}
			if (tN > 1)
				printf("2 %lld %lld\n", n - two[0], n - two[1]);
			else if (tN > 0)
				printf("2 %lld %lld\n", n - two[0], one[0] + two[0]);
			else
				printf("2 %lld %lld\n", n - one[0] - one[1], one[0] + one[1] + one[2]);
		}
	}
	return 0;
}
