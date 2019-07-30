#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <queue>

//using namespace std;
using std::scanf;
using std::printf;
using std::putchar;
using std::puts;
using std::memset;
using std::queue;

const int maxN = 500000 + 7;
const int L = 0;
const int R = -1;
int statu[maxN], pre[maxN], vis[maxN], left[maxN], right[maxN];
long long fuck[maxN];

int main()
{
	memset(fuck, 0LL, sizeof(fuck));
	int n = 0;
	scanf("%lld%d", &fuck[1], &n);
	memset(pre, 0, sizeof(pre));
	memset(vis, false, sizeof(vis));
	for (int i = 1; i <= n; i++)
	{
		char s[5];
		scanf("%s%d%d", s, &left[i], &right[i]);
		statu[i] = s[0] == 'L' ? L : R;
		pre[left[i]]++;
		pre[right[i]]++;
	}
	queue<int> Q;
	for (int i = 1; i <= n; i++)
	{
		if (pre[i] == 0)
			Q.push(i);
	}
	while (!Q.empty())
	{
		int now = Q.front();
		Q.pop();
		if (fuck[now] == 0)
		{
			if (--pre[left[now]] == 0)
				Q.push(left[now]);
			if (--pre[right[now]] == 0)
				Q.push(right[now]);
			continue;
		}
		long long small_fuck = fuck[now] / 2;
		long long big_fuck = small_fuck + (fuck[now] & 1);
		if (statu[now] == L)
		{
			fuck[left[now]] += big_fuck;
			fuck[right[now]] += small_fuck;
		}
		else
		{
			fuck[left[now]] += small_fuck;
			fuck[right[now]] += big_fuck;
		}
		if (--pre[left[now]] == 0)
			Q.push(left[now]);
		if (--pre[right[now]] == 0)
			Q.push(right[now]);
		vis[now] = true;
		if ((fuck[now] & 1) == 1)
			statu[now] = ~statu[now];
	}

	for (int i = 1; i <= n; i++)
		putchar(statu[i] == L ? 'L' : 'R');
	puts("");
	return 0;
}
