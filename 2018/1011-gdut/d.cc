#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int t = 0;
	scanf("%d", &t);
	while (t--)
	{
		static int f[107][3];
		memset(f, 0x7f, sizeof(f));
		f[0][0] = 0;
		int n = 0;
		scanf("%d", &n);
		for (int i = 1; i <= n; i++)
		{
			int x = 0;
			scanf("%d", &x);
			f[i][0] = min(f[i - 1][0], min(f[i - 1][1], f[i - 1][2])) + 1;
			if (x & 1)
				f[i][1] = min(f[i - 1][0], f[i - 1][2]);
			if (x >> 1)
				f[i][2] = min(f[i - 1][0], f[i - 1][1]);
		}
		printf("%d\n", min(f[n][0], min(f[n][1], f[n][2])) * -24);
	}
	return 0;
}
