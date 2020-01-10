#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <map>
#include <string>

using namespace std;

map<char, string> M;

void init()
{
	M['a'] = "as";
	M['i'] = "ios";
	M['y'] = "ios";
	M['l'] = "les";
	M['n'] = "anes";
	M['o'] = "os";
	M['r'] = "res";
	M['t'] = "tas";
	M['u'] = "us";
	M['v'] = "ves";
	M['w'] = "was";
}

int main()
{
	init();
	int t = 0;
	scanf("%d", &t);
	while (t--)
	{
		static char s[50];
		scanf("%s", s);
		int n = strlen(s);
		if (s[n - 1] == 'e' && s[n - 2] == 'n')
			s[--n] = 0;
		if (M.find(s[n - 1]) != M.end())
		{
			const char *t = M[s[n - 1]].c_str();
			s[--n] = 0;
			strcat(s, t);
		}
		else
			strcat(s, "us");
		puts(s);
	}
	return 0;
}
