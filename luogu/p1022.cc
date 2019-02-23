#include <cstdio>
#include <cstring>
#include <cctype>
#include <iostream>
#include <algorithm>

using namespace std;

const int maxN = (int)1e6;
char sta[maxN];

struct P { int c1, c0; };

P calc(char *s)
{
	int c1 = 0, c0 = 0;
	int sign = 1, val = 0;
	if (*s == '-')
	{
		sign = -1;
		s++;
	}
	while (*s != '\0')
	{
		if (isdigit(*s))
		{
			if (sign == 1)
			{
				val = *s - '0';
				sign++;
			}
			else if (sign == -1)
			{
				val = -(*s - '0');
				sign--;
			}
			else if (sign == 2)
				val = val * 10 + (*s - '0');
			else if (sign == -2)
				val = val * 10 - (*s - '0');
		}
		else if (*s == '+')
		{
			if (sign == 2 || sign == -2)
				c0 += val;
			else 
				c1 += val;
			sign = 1;
		}
		else if (*s == '-')
		{
			if (sign == 2 || sign == -2)
				c0 += val;
			else
				c1 += val;
			sign = -1;
		}
		else
		{
			if (sign == 1)
				val = 1;
			else if (sign == -1)
				val = -1;
			if (sign > 0)
				sign = 3;
			else
				sign = -3;
		}
		s++;
	}
	if (sign == 2 || sign == -2)
		c0 += val;
	else
		c1 += val;
	return {c1, c0};
}

int main()
{
	scanf("%s", sta);
	for (char *ch = sta; *ch != '\0'; ch++)
	{
		if (isalpha(*ch))
		{
			printf("%c=", *ch);
			break;
		}
	}
	char *stb = sta;
	while (*stb != '=')
		stb++;
	*(stb++) = '\0';
	P left = calc(sta);
	P right = calc(stb);
	//cout << left.c1 << ' ' << left.c0 << ' ' << right.c1 << ' ' << right.c0 << endl;
	printf("%.3f", (double)(right.c0 - left.c0) / (left.c1 - right.c1) + 1e-9);
	return 0;
}
