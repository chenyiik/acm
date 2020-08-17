#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

//bool cmp(const char *a, const char *b) { return a[1] < b[1] || (a[1] == b[1] && a[0] < b[0]); }
bool cmp(const string &a, const string &b) { return a[1] < b[1] || (a[1] == b[1] && a[0] < b[0]); }

int main()
{
	//char s[3][10];
	//scanf("%s%s%s", s[0], s[1], s[2]);
	string s[3];
	cin >> s[0] >> s[1] >> s[2];
	sort(s, s + 3, cmp);
	if (s[0] == s[1] && s[0] == s[2])
		puts("0");
	else if (s[0][1] == s[1][1] && s[0][1] == s[2][1] && s[0][0] + 1 == s[1][0] && s[0][0] + 2 == s[2][0])
		puts("0");
	else if (s[0] == s[1] || s[1] == s[2])
		puts("1");
	else if (s[0][1] == s[1][1] && s[0][0] + 1 == s[1][0])
		puts("1");
	else if (s[1][1] == s[2][1] && s[1][0] + 1 == s[2][0])
		puts("1");
	else if (s[0][1] == s[1][1] && s[0][0] + 2 == s[1][0])
		puts("1");
	else if (s[1][1] == s[2][1] && s[1][0] + 2 == s[2][0])
		puts("1");
	else
		puts("2");
	return 0;
}
