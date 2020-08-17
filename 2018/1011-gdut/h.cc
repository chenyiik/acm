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
		const int N = static_cast<int>(1e6) + 5;
		static int a[N], nt0[N], nt1[N], hd0[65536], hd1[65536];
		memset(hd0, -1, sizeof(hd0));
		memset(hd1, -1, sizeof(hd1));
		int n = 0;
		scanf("%d", &n);
		for (int i = 0; i < n; i++)
		{
			scanf("%d", &a[i]);
			int k = a[i] & 65535;
			nt0[i] = hd0[k];
			hd0[k] = i;
		}
		a[n] = 0x7fffffff;
		nt0[n] = hd0[0xffff];
		hd0[0xffff] = n;
		for (int i = 65535; i >= 0; i--)
		{
			for (int j = hd0[i]; j != -1; j = nt0[j])
			{
				int k = a[j] >> 16;
				nt1[j] = hd1[k];
				hd1[k] = j;
			}
		}
		int b = 0, a0 = -1, a1 = -1;
		for (int i = 0; i < 65536; i++)
		{
			for (int j = hd1[i]; j != -1; j = nt1[j])
			{
				if (a0 != a1 && a1 != a[j])
					printf("%d%c", a1, (!b++ ? ' ' : '\n'));
				a0 = a1;
				a1 = a[j];
			}
		}
	}
	return 0;
}
