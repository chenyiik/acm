#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int maxn = 105;
char s[maxn], t[maxn], p[maxn];
int tot[30];

int sol()
{
	memset(tot, 0, sizeof(tot));
	scanf("%s%s%s", s, t, p);
	for (char *i = p; *i != 0; i++)
		tot[*i - 'a']++;
	char *j = s;
	for (char *i = t; *i != 0; i++)
	{
		//cout << *i << ' ' << *j << endl;
		if (*i == *j)
			j++;
		else if (tot[*i - 'a'] > 0)
			tot[*i - 'a']--;
		else
			return puts("NO");

	}
	return puts(*j == 0 ? "YES" : "NO");
}

int main()
{
	int t;
	scanf("%d", &t);
	while (t--)
		sol();
	return 0;
}
