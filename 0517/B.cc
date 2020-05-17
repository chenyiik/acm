#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	for (int n; ~scanf("%d", &n); )
	{
		int k = 0;
		for (int mark = 0x3ff; mark; k++)
		{
			long long sum = (long long)n * (k + 1);
			while (sum)
			{
				int x = sum % 10;
				mark &= ~(1 << x);
				sum /= 10;
			}
		}
		printf("%d\n", k);
	}
	return 0;
}
