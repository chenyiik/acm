#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

int a[16][4], sum[16];
bool vis[32];

int main()
{
	//for (int i = 0; i < 16; i++)
	for (int i = 0; i < 8; i++)
	{
		//a[i][3] = i >> 3 & 1;
		a[i][2] = i >> 2 & 1;
		a[i][1] = i >> 1 & 1;
		a[i][0] = i >> 0 & 1;
	}
	//for (int i = 0; i < (1 << 18); i++) 
	for (int i = 0; i < (1 << 9); i++) 
	{
		int tot = 0, num = i;
		while (num) tot += num & 1, num >>= 1;
		if (tot > 5) continue;
		memset(sum, 0, sizeof(sum));
		num = i;
		for (int j = 0; num; j++, num >>= 1) if (num & 1)
		{
			int x, y;
			if (j / 3 == 0) x = 0, y = 1;
			if (j / 3 == 1) x = 0, y = 2;
			if (j / 3 == 2) x = 1, y = 2;
			//if (j / 3 == 0) x = 0, y = 1;
			//if (j / 3 == 1) x = 0, y = 2;
			//if (j / 3 == 2) x = 0, y = 3;
			//if (j / 3 == 3) x = 1, y = 2;
			//if (j / 3 == 4) x = 1, y = 3;
			//if (j / 3 == 5) x = 2, y = 3;
			if (j % 3 == 0) // &
				//for (int k = 0; k < 16; k++)
				for (int k = 0; k < 8; k++)
					sum[k] = sum[k] << 1 | (a[k][x] & a[k][y]);
			if (j % 3 == 1) // |
				//for (int k = 0; k < 16; k++)
				for (int k = 0; k < 8; k++)
					sum[k] = sum[k] << 1 | (a[k][x] | a[k][y]);
			if (j % 3 == 2) // ^
				//for (int k = 0; k < 16; k++)
				for (int k = 0; k < 8; k++)
					sum[k] = sum[k] << 1 | (a[k][x] ^ a[k][y]);
		}
		memset(vis, false, sizeof(vis));
		bool flag = true;
		//for (int j = 0; j < 16; j++)
		for (int j = 0; j < 8; j++)
		{
			if (vis[sum[j]])
			{
				flag = false;
				break;
			}
			else
			{
				vis[sum[j]] = true;
			}
		}
		if (flag)
		{
			cout << i << endl;
			num = i;
			for (int j = 0; num; j++, num >>= 1) if (num & 1)
				cout << j << ' ';
			cout << endl;
		}
	}
	return 0;
}
