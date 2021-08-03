#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <string>
#include <set>

using namespace std;

char s[50];

int main()
{
	set<int> S;
	int _; scanf("%d", &_);;
	while (_--)
	{
		int h; scanf("%d%s", &h, s);
		if (string(s) == string("divide_by_three"))
		{
			for (int i = 0; i <= 4; i++) if ((h + i) % 3 == 0)
			{
				printf("%d\n", i);
				break;
			}
		}
		else if (string(s) == string("divide_by_four"))
		{
			for (int i = 0; i <= 4; i++) if ((h + i) % 4 == 0)
			{
				printf("%d\n", i);
				break;
			}
		}
		else if (string(s) == string("divide_by_five"))
		{
			for (int i = 0; i <= 4; i++) if ((h + i) % 5 == 0)
			{
				printf("%d\n", i);
				break;
			}
		}
		else if (string(s) == string("indivisible"))
		{
			for (int i = 0; i <= 4; i++) 
			{
				int k = h + i;
				if (k == 2 || k == 3 || k == 5 || k == 7 || k == 11)
				{
					printf("%d\n", i);
					break;
				}
			}
		}
	}
	return 0;
}
