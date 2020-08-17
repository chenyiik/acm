#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const long long maxN = static_cast<int>(1e7) + 7;
const long long maxM = static_cast<int>(2e5) + 7;
int head[maxN], nxt[maxM];
int a[maxM], b[maxM], c[maxM];

int main()
{
	int n = 0;
	scanf("%d", &n);
	memset(head, -1, sizeof(head));
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
		nxt[i] = head[a[i]];
		head[a[i]] = i;
	}
	int cnt = n;
	for (long long i = 1; i < maxN; i++)
		for (long long j = i * i; j < maxN; j += i)
			if (head[j] != -1)
			{
				int x = head[j];
				head[j] = nxt[x];
				b[x] = i;
				c[x] = j / i;
				cnt--;
				if (head[j] != -1 && j != i * i)
				{
					x = head[j];
					head[j] = nxt[x];
					b[x] = j / i;
					c[x] = i;
					cnt--;
				}
			}
	if (cnt != 0)
	{
		puts("NO");
		return 0;
	}
	puts("YES");
	for (int i = 0; i < n; i++)
		printf("%d %d\n", b[i], c[i]);
	return 0;
}
