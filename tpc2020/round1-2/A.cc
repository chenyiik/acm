#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

char s[8][5], a[50];

int main()
{
	int _; scanf("%d", &_);
	while (_--)
	{
		scanf("%s", a);
		int len = strlen(a), split = 0;
		while (split < len)
			if (a[split] == ':' && a[split + 1] == ':') break;
			else split++;
		memset(s, 0, sizeof(s));
		for (int i = 0, j = 0, k = 0; i < split; i++)
		{
			if (a[i] == ':')
				j++, k = 0;
			else
				s[j][k++] = a[i];
		}
		char temp[4];
		for (int i = len - 1, j = 7, k = 4; i > split; i--)
		{
			if (a[i] == ':')
			{
				for (int l = 0, r = k; r < 4; l++, r++)
					s[j][l] = temp[r];
				j--, k = 4;
			}
			else
				temp[--k] = a[i];
		}
		for (int i = 0; i < 8; i++)
		{
			int le = strlen(s[i]);
			for (int j = 0; j < 4 - le; j++)
				putchar('0');
			printf("%s", s[i]);
			//printf("%04s%c", s[i], ":\n"[i == 7]);
			putchar(":\n"[i == 7]);
		}
	}
	return 0;
}
