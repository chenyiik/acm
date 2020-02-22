#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int maxn = int(2e5) + 5;
char s[maxn];
int dist[maxn];

int main()
{
	int n; scanf("%s%d", s, &n);
	int len = strlen(s);
	for (int i = 0; i < n - 1; i++)
		s[i + len] = s[i];
	int le = len;
	len = len + n - 1;
	int now_dist = 0x3fffffff;
	for (int i = len - 1; i >= 0; i--)
	{
		if (s[i] == 'E')
			dist[i] = now_dist = 0;
		else
			dist[i] = ++now_dist;
	}
	long long ans = 0;
	for (int i = 0; i < le; i++)
	{
		if (dist[i] >= 0x3fffffff)
			break;
		int tmp = min(n - dist[i], len - (i + dist[i]));
		//cout << tmp << ' ';
		ans += max(0, tmp);
	}
	printf("%lld\n", ans);
	return 0;
}
