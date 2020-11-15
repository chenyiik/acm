#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int maxn = int(1e3);
int vis[maxn], mark[maxn];

void init()
{
	for (int i = 2; i < maxn; i++) if (!vis[i])
		for (int j = i * i; j < maxn; j += i)
			vis[j] = true;
}

int main()
{
	init();
	int _; scanf("%d", &_);
	while (_--)
	{
		int n; scanf("%d", &n);
		for (int i = 0; i < n; i++)
			printf("%d%c", n * 4 - i * 2, " \n"[i + 1 == n]);
		/*
		int m = n;
		memset(mark, 0, sizeof(mark));
		for (int i = 2; i < maxn; i++)
		{
			if (vis[i]) continue;
			if (i * 4 <= 4 * m && !mark[i * 4])
			{
				printf("%d%c", i * 4, " \n"[n == 1]);
				mark[i * 4] = true;
				if (--n == 0) break;
			}
			if (i * 6 <= 4 * m && !mark[i * 6])
			{
				printf("%d%c", i * 6, " \n"[n == 1]);
				mark[i * 6] = true;
				if (--n == 0) break;
			}
			if (i * 10 <= 4 * m && !mark[i * 10])
			{
				printf("%d%c", i * 10, " \n"[n == 1]);
				mark[i * 10] = true;
				if (--n == 0) break;
			}
			if (i * 14 <= 4 * m && !mark[i * 14])
			{
				printf("%d%c", i * 14, " \n"[n == 1]);
				mark[i * 14] = true;
				if (--n == 0) break;
			}
			if (i * 22 <= 4 * m && !mark[i * 22])
			{
				printf("%d%c", i * 22, " \n"[n == 1]);
				mark[i * 22] = true;
				if (--n == 0) break;
			}
			if (i * 26 <= 4 * m && !mark[i * 26])
			{
				printf("%d%c", i * 26, " \n"[n == 1]);
				mark[i * 26] = true;
				if (--n == 0) break;
			}
		}
		*/
	}
	return 0;
}
