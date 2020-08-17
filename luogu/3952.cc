#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int t = 0;
	scanf("%d", &t);
	while (t--)
	{
		int line = 0;
		char ast_s[20];
		scanf("%d%s", &line, ast_s);
		int ast = 0;
		if (ast_s[2] == 'n')
			sscanf(ast_s + 4, "%d", &ast);
		static char s[20];
		fgets(s, 15, stdin);
		static char cv[1000];
		static bool cb[1000];
		int cnt = 0, cot = 0, mot = 0, lock = 0, cbt = 0;
		bool err = false;
		for (int i = 0; i < line; i++)
		{
			fgets(s, 15, stdin);
			if (err)
				continue;
			if (s[0] == 'F')
			{
				char r[5], p[5], q[5];
				sscanf(s + 1, "%s%s%s", r, p, q);
				for (int j = 0; j < cnt; j++)
				{
					if (r[0] == cv[j])
					{
						err = true;
						break;
					}
				}
				if (err)
				{
					//cout << 'R' << endl;
					continue;
				}
				cv[cnt++] = r[0];
				if (lock)
				{
					lock++;
					continue;
				}
				if (p[0] != 'n' && q[0] == 'n')
				{
					mot = max(mot, ++cot);
					cb[cbt++] = 1;
				}
				else if (p[0] == 'n' && q[0] != 'n')
					lock = 1;
				else if (p[0] != 'n' && q[0] != 'n')
				{
					int x = 0, y = 0;
					sscanf(p, "%d", &x);
					sscanf(q, "%d", &y);
					//cout << p << ' ' << q << endl;
					//cout << x << ' ' << y << endl;
					if (x > y)
						lock = 1;
					else
						cb[cbt++] = 0;
				}
			}
			else
			{
				if (--cnt < 0)
				{
					err = true;
					//cout << 'E' << endl;
				}
				if (lock)
					lock--;
				else if (cb[--cbt])
					cot--;
			}
		}
		if (err || cnt != 0)
			puts("ERR");
		else
		{
			//cout << mot << endl;
			puts(ast == mot ? "Yes" : "No");
		}
	}
	return 0;
}
