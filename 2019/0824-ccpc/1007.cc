#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

char s[1100][1100];
int two[11];

int main()
{
	int t; scanf("%d", &t);
	two[1] = 2;
	for (int i = 2; i <= 10; i++)
		two[i] = two[i - 1] * 2;
	s[1][1] = s[1][2] = s[2][2] = 'C';
	s[2][1] = 'P';
	for (int k = 2; k <= 10; k++)
	{
		for (int i = 1; i <= two[k - 1]; i++)
			for (int j = 1; j <= two[k - 1]; j++)
			{
				s[i][j + two[k - 1]] = s[i][j];
				s[i + two[k - 1]][j + two[k - 1]] = s[i][j];
				s[i + two[k - 1]][j] = s[i][j] ^ ('C' ^ 'P');
			}
	}
			
	while (t--)
	{
		int n;
		scanf("%d", &n);
		for (int i = 1; i <= two[n]; i++)
		{
			for (int j = 1; j <= two[n]; j++)
				putchar(s[i][j]);
			puts("");
		}
	}
	return 0;
}
