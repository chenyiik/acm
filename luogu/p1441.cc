#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

bool next_c(bool b[], int n, int m)
{
	for (int i = 1; i <= m; i++)
	{
		int j = n - i;
		while (!b[j])
			j--;
		if (j != n - i)
		{
			for (int k = j; k < n; k++)
				b[k] = false;
			for (int k = 1; k <= i; k++)
				b[j + k] = true;
			return true;
		}
	}
	return false;
}

int main()
{
	int n = 0, m = 0;
	scanf("%d%d", &n, &m);
	static int a[25];
	static bool b[25];
	for (int i = 0;i < n; i++)
		scanf("%d", &a[i]);
	for (int i = 0; i < m; i++)
		b[i] = true;
	int ans = 0;
	do
	{
		int tot = 0;
		static bool f[2005];
		memset(f, false, sizeof(f));
		f[0] = true;
		for (int i = 0; i < n; i++)
			if (!b[i])
				for (int j = 2000 - a[i]; j >= 0; j--)
					f[j + a[i]] = f[j + a[i]] || f[j];
		for (bool i : f)
			if (i)
				tot++;
		ans = max(ans, tot - 1);
	} while (next_c(b, n, m));
	printf("%d\n", ans);
	return 0;
}
