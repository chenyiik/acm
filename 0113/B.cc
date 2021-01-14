#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

int a[50][50];

int main()
{
	int n; scanf("%d", &n);
	if (n == 2 || n == 3)
	{
		puts("-1");
		return 0;
	}
	printf("%d\n", n);
	int c = 1;
	for (int i = 0; i < n; i++)
	{
		int j = n / 2;
		do
		{
			a[i][j] = c++;
			if (j >= n / 2) j -= n / 2;
			else j += n / 2 + 1;
		} while (j != n / 2 && j != n);
	}
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			printf("%d%c", a[i][j], " \n"[j + 1 == n]);
	return 0;
}
