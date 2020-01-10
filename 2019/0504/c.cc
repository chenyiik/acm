#include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>

using namespace std;

const char *IMP = "IMPOSSIBLE";

int main()
{
	int t = 0;
	scanf("%d", &t);
	while (t--)
	{
		int n = 0;
		scanf("%d", &n);
		int n2 = n * 2, m = static_cast<int>(sqrt(n2 + 0.5));
		bool b = false;
		//for (int i = m; i >= 2; i--)
		for (int i = 2; i <= m; i++)
		{
			int mid2 = n2 / i;
			//cout << i << endl;
			if (n2 % i != 0 || i % 2 == mid2 % 2)
				continue;
			int a = (mid2 + 1 - i) / 2;
			//cout << '\t' << a << endl;
			if (a < 1)
				continue;
			printf("%d = %d", n, a);
			for (int j = a + 1; j < a + i; j++)
				printf(" + %d", j);
			puts("");
			b = true;
			break;
		}
		if (!b)
			puts(IMP);
	}
	return 0;
}
