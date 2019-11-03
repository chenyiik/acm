#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

const int maxn = int(1e6) + 10;
int p[maxn * 10], *a[maxn], m[maxn];
long long cnt[maxn];

void init(int);
bool read(int &ret)
{
	char c; int sgn;
	if (c = getchar(), c == EOF) return 0;
	while (c != '-' && (c < '0' || c > '9')) c = getchar();
	sgn = (c == '-') ? -1 : 1;
	ret = (c == '-') ? 0 : c - '0';
	while (c = getchar(), c >= '0' && c <= '9')
		ret = ret * 10 + c - '0';
	ret *= sgn;
	return 1;
}

int main()
{
	int t; scanf("%d", &t);
	while (t--)
	{
		int n; scanf("%d", &n);
		init(n);
		cnt[n] = 1;
		for (int q = n; q > 0; q--) if (a[q][0] == 2)
		{
			cnt[a[q][1]] += cnt[q];
			cnt[a[q][2]] += cnt[q];
		}
		unordered_map<int, long long> M;
		long long tot = 0;
		for (int q = 1; q <= n; q++) if (a[q][0] == 1 && cnt[q])
		{
			tot += a[q][1] * cnt[q];
			for (int i = 2; i < m[q]; i++)
			{
				auto it = M.find(a[q][i]);
				if (it == M.end())
					M[a[q][i]] = cnt[q];
				else
					it->second += cnt[q];
			}
		}
		long long ans = tot;
		for (auto i : M)
			if (i.second * 2 > tot)
				ans = (tot - i.second) * 2;
		printf("%lld\n", ans);
	}
	return 0;
}

void init(int n)
{
	a[1] = p;
	for (int i = 1; i <= n; i++)
	{
		cnt[i] = 0;
		scanf("%d", &a[i][0]);
		if (a[i][0] == 1)
		{
			scanf("%d", &a[i][1]);
			m[i] = a[i][1] + 2;
			for (int j = 2; j < m[i]; j++)
				scanf("%d", &a[i][j]);
		}
		else
		{
			m[i] = 3;
			scanf("%d%d", &a[i][1], &a[i][2]);
		}
		a[i + 1] = a[i] + m[i];
	}
}
