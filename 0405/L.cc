#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

typedef long long LL;

LL ct(const char s[])
{
	int len = strlen(s);
	LL sum = 0, cnt = 1;
	for (int i = len - 1; i >= 0; i--)
		sum += cnt * (s[i] == '1'), cnt *= 2;
	return sum;
}

void rm(char s[], int pos)
{
	for (int i = pos; s[i] != '\0'; i++)
		s[i] = s[i + 1];
}

int main()
{
	LL k; scanf("%lld", &k);
	static char s[70]; scanf("%s", s);
	int ans = 0;
	for (int i = 1; s[i] != '\0' && ct(s) > k; i++)
	{
		if (s[i] == '1')
			rm(s, i), ans++, i--;
	}
	while (ct(s) > k)
		rm(s, 1), ans++;
	printf("%d\n", ans);
	return 0;
}
