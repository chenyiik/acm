#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int maxn = int(2e6) + 5;
char s[maxn];

int main()
{
	int m; scanf("%s%d", s, &m);
	int n = strlen(s), mov = 0;
	while (m--)
	{
		char op[2]; int x; scanf("%s%d", op, &x);
		if (*op == 'A')
			printf("%c\n", s[(mov + x - 1) % n]);
		else // if (*op == 'M')
		{
			mov += x;
			while (mov < 0) mov += n;
			if (mov > n) mov %= n;
		}
	}
	return 0;
}
