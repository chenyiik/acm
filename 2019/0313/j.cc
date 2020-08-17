#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

char show(int p)
{
	if (p < 0)
		return '<';
	else if (p == 0)
		return '=';
	else
		return '>';
}

int main()
{
	int t = 0;
	scanf("%d", &t);
	for (int i = 1; i <= t; i++)
	{
		char a0[5], a1[5], a2[5];
		char b0[5], b1[5], b2[5];
		scanf("%1s%1s%s%1s%1s%s", a0, a1, a2, b0, b1, b2);
		if (a1[0] != b1[0])
			a2[3] = b2[3] = '\0';
		printf("Case %d: %c %c\n", i, show(strcmp(a0, b0)), show(strcmp(a2, b2)));
	}
	return 0;
}
