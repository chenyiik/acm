#include <cstdio>
#include <cstring>
#include <cctype>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

void init(int table[])
{
	table[00] = 0x0000;
	table[20] = 0x0011;
	table[21] = 0x1100;
	table[22] = 0x0110;
	table[23] = 0x1001;
	table[24] = 0x1010;
	table[25] = 0x0101;
	table[30] = 0x0111;
	table[31] = 0x1110;
	table[32] = 0x1011;
	table[33] = 0x1101;
	table[40] = 0x1111;
}

int read()
{
	int ans = 0;
	char c = '\0';
	while (!isdigit(c = getchar()))
		;
	do
	{
		ans *= 10;
		ans += (c & 0xf);
	} while (isdigit(c = getchar()));
	return ans;
}

int main()
{
	static int table[50];
	init(table);
	int t(read());
	for (int cas = 1; cas <= t; cas++)
	{
		static const char *sn = "What a pity!\n";
		static const char *sy = "Well done!\n";
		static int a[1005][1005];
		int n(read()), m(read());
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				int x(read()), y(read());
				int z = x * 10 + y;
				a[i][j] = table[z];
			}
		}

		bool vis[1005][1005];
		memset(vis, false, sizeof(vis));
		queue<int> Q;
		Q.push(0);
		vis[0][0] = true;
		while (!Q.empty())
		{
			int q = Q.front();
			Q.pop();
			int x = q >> 24, y = q & 0xfff;
			if (x < n - 1 && (a[x][y] & 0x0100) && (a[x + 1][y] & 0x1000))
			{
				Q.push((x + 1 << 24) + y);
				vis[x + 1][y] = true;
			}
			if (y < m - 1 && (a[x][y] & 0x0001) && (a[x][y + 1] & 0x0010))
			{
				Q.push((x << 24) + y + 1);
				vis[x][y + 1] = true;
			}
		}
		printf("Case %d:\n%s", cas, (vis[n - 1][m - 1] ? sy : sn));
	}
	return 0;
}
