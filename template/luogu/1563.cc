#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int maxN = (int)1e5 + 7;
char s[maxN][15];
int a[maxN];

int main()
{
	int n = 0, m = 0;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++)
		scanf("%d%s", &a[i], s[i]);
	int cnt = 0;
	while (m--)
	{
		int b = 0, c = 0;
		scanf("%d%d", &b, &c);
		cnt += a[cnt] != b ? c : -c;
		cnt %= n;
		if (cnt < 0)
			cnt += n;
	}
	puts(s[cnt]);
	return 0;
}
