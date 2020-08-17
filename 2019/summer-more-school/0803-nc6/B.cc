#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

char s[20], t[8][8];

int main()
{
	int TN = 0;
	scanf("%d", &TN);
	for (int T = 1; T <= TN; T++)
	{
		for (int i = 0; i < 8; i++)
		{
			scanf("%16s", s);
			int tmp = 0;
			for (int j = 0; j < 16; j++)
				if (s[j] == '1')
					tmp += 1 << (16 - j - 1);
			sprintf(t[i], "%x%c", tmp, "\0:"[i < 7]);
			//printf("%s", t[i]);
		}
		int pos = -1, len = 0, star = -1;
		for (int i = 0; i < 8; i++)
		{
			if (t[i][0] != '0')
				pos = -1;
			else 
			{
				if (pos == -1)
					pos = i;
				else if (i - pos + 1 > len)
					star = pos, len = i - pos + 1;
				else if (i - pos + 1 == len && (star == 0 || i < 7))
					star = pos, len = i - pos + 1;
			}
		}
		if (star > -1 && len > 1)
		{
			if (star == 0)
				strcpy(t[star], "::");
			else
				strcpy(t[star], ":");
			for (int i = star + 1; i < star + len; i++)
				strcpy(t[i], "");
		}
		printf("Case #%d: ", T);
		for (int i = 0; i < 8; i++)
			printf("%s", t[i]);
		puts("");
	}
	return 0;
}
