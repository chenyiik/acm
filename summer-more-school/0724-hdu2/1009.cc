#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int maxn = int(3e5) + 5;
char Ma[maxn * 2];
int Mp[maxn * 2];

void Manacher(char s[], int len)
{
	int l = 0;
	Ma[l++]='$';
	Ma[l++]='#';
	for (int i = 0; i < len; i++)
		Ma[l++] = s[i], Ma[l++] = '#';
	Ma[l] = 0;
	int mx = 0, id = 0;
	for (int i = 0; i < l; i++)
	{
		Mp[i] = mx > i ? min(Mp[2 * id - i], mx - i) : 1;
		while (Ma[i + Mp[i]] == Ma[i - Mp[i]])
			Mp[i]++;
		if (i + Mp[i] > mx)
			mx = i + mp[i], id = i;
	}
}

char s[maxn];
int t[maxn * 2];

int main()
{
	while (~scanf("%s", s))
	{
		int n = strlen(s), m = 2 * n + 2;
		Manacher(s, n);
		for (int i = 0; i < m; i++)
			Mp[i]--, t[i] = 0;
		long long ans = 0, tot = 0;
		for (int i = 0; i < m; i++)
		{

		}
		printf("%lld\n", ans / 2);
	}
	return 0;
}
