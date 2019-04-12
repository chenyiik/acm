#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 35;
int a[N][N];

int main()
{
	for (int n; ~scanf("%d", &n) && n; )
	{
		for (int i = 1; i <= n; i++)
		{
			a[i][i] = 0;
			for (int j = i + 1; j <= n; j++)
			{
				scanf("%d", &a[i][j]);
				a[j][i] = a[i][j];
			}
		}

	}
	return 0;
}
