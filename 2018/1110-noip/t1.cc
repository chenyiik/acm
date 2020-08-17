#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int maxN = 100007, maxD = 10007;
int deep[maxN], head[maxD], nxt[maxN];

int main()
{
	int n = 0;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &deep[i]);
		nxt[i] = head[deep[i]];
		head[deep[i]] = i;
	}
	int block = 0, ans = 0;
	for (int i = 1; i <= n; i++)
	{
		if (deep[i - 1] == 0 && deep[i] > 0)
			block++;
	}
	for (int i = 1; block; i++)
	{
		ans += block;
		for (int j = head[i]; j; j = nxt[j])
		{
			if (deep[j] > deep[j - 1] && deep[j] >= deep[j + 1])
				block--;
			else if (deep[j] <= deep[j - 1] && deep[j] < deep[j + 1])
				block++;
		}
	}
	printf("%d\n", ans);
	return 0;
}
