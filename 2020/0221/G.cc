#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int maxn = 105;
bool A[maxn][maxn], B[maxn][maxn];
int tota[maxn], totb[maxn];

struct P { int x, y, z; };

void show(const vector<P> &ans);

int main()
{
	int n, m, h; scanf("%d%d%d", &n, &m, &h);
	for (int i = 0; i < n; i++)
	{
		static char s[maxn]; scanf("%s", s);
		for (int j = 0; j < m; j++)
			if (s[j] == '1')
				A[i][j] = true, tota[i]++;
	}
	for (int i = 0; i < n; i++)
	{
		static char s[maxn]; scanf("%s", s);
		for (int j = 0; j < h; j++)
			if (s[j] == '1')
				B[i][j] = true, totb[i]++;
	}
	for (int i = 0; i < n; i++)
		if ((tota[i] == 0) != (totb[i] == 0))
			return puts("-1"), 0;
	vector<P> ans;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			for (int k = 0; k < h; k++)
				if (A[i][j] && B[i][k])
					ans.push_back({i, j, k});
	show(ans);
	ans.clear();
	for (int i = 0; i < n; i++)
	{
		if (!tota[i])
			continue;
		int y = 0, z = 0;
		while (!A[i][y])
			y++;
		while (!B[i][z])
			z++;
		while (tota[i] > totb[i])
		{
			if (A[i][y])
				ans.push_back({i, y, z}), tota[i]--;
			y++;
		}
		while (tota[i] < totb[i])
		{
			if (B[i][z])
				ans.push_back({i, y, z}), totb[i]--;
			z++;
		}
		while (tota[i]--)
		{
			while (!A[i][y])
				y++;
			while (!B[i][z])
				z++;
			ans.push_back({i, y, z}), y++, z++;
		}
	}
	show(ans);
	return 0;
}

void show(const vector<P> &ans)
{
	printf("%lu\n", ans.size());
	for (const auto &i : ans)
		printf("%d %d %d\n", i.x, i.y, i.z);
}
