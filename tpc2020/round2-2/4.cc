#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int maxn = int(1e5) + 5;
char s[maxn], t[maxn * 10];

int main()
{
	int _; scanf("%d", &_);
	while (_--)
	{
		scanf("%s", s + 1);
		int q; scanf("%d", &q);
		while (q--)
		{
			char op[4]; scanf("%s", op);
			if (op[0] == '+')
			{
				int p; scanf("%d%s", &p, t);
			}
			else if (op[0] == '!')
			{
				int a, b, c, p; scanf("%d%d%d%d", &a, &b, &c, &p);
			}
			else if (op[0] == '?')
			{
				int p; scanf("%d", &p);
			}
		}
	}
	return 0;
}
