#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int maxn = int(1e5) + 10;
char s[maxn], t[maxn];

int f()
{
	int n; scanf("%d%s%s", &n, s, t);
	int tot = 0;
	for (int i = 0; i < n; i++) if (s[i] != t[i])
	{
		if (i > 0 && s[i] == s[i - 1])
			return -1;
		s[i] = s[i] ^ '1' ^ '0';
		for (int j = i + 1; j < n && s[j] != s[i]; j++)
			s[j] = s[j] ^ '1' ^ '0';
		tot++;
	}
	return tot;
}

int main()
{
	int _; scanf("%d", &_);
	while (_--)
		printf("%d\n", f());
	return 0;
}
