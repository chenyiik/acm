#include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>

using namespace std;

bool b;

void show(int k, char c)
{
	if (k == 0)
		return;
	if (k > 0 && b)
		putchar('+');
	if (k < 0)
		putchar('-');
	if (c == '\0')
		printf("%d", abs(k));
	else if (abs(k) == 1)
		putchar(c);
	else
		printf("%d%c", abs(k), c);
	b = true;
}

int main()
{
	int t = 0;
	scanf("%d", &t);
	while (t--)
	{
		b = false;
		int k = 0;
		for (char c = 'p'; c <= 'r'; c++)
		{
			scanf("%d", &k);
			show(k, c);
		}
		for (char c = 'u'; c <= 'z'; c++)
		{
			scanf("%d", &k);
			show(k, c);
		}
		scanf("%d", &k);
		show(k, '\0');
		if (!b)
			putchar('0');
		puts("");
	}
	return 0;
}
