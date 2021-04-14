#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

int t[50], a[105];

int main()
{
	for (int i = 1; i < 50; i++)
		t[i] = (i * 2) * (i * 2) / 2;
	int T; scanf("%d", &T);
	while (T--)
	{
		int n, k; scanf("%d%d", &n, &k);
		for (int i = 1; n; i++)
		{
			if (n % 2 == 0)
				continue;
		}
	}
	return 0;
}
