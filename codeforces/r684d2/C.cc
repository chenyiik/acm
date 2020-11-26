#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int maxn = 105;
char s[maxn][maxn];

struct P
{
	int a[6];
	P(int b, int c, int d, int e, int f, int g) {
		a[0] = b; a[1] = c; a[2] = d; a[3] = e; a[4] = f; a[5] = g;
		s[b][c] ^= 1, s[d][e] ^= 1, s[f][g] ^= 1;
	}
};

int get2x2()
{
	int ret = 0;
	for (int i = 1; i < 3; i++) for (int j = 1; j < 3; j++)
		ret = ret << 1 | s[i][j] & 1;
	return ret;
}

int main()
{
	int T; scanf("%d", &T);
	while (T--)
	{
		int n, m; scanf("%d%d", &n, &m);
		for (int i = 1; i <= n; i++) scanf("%s", s[i] + 1);
		vector<P> v;
		for (int i = n; i > 2; i--) for (int j = 1; j <= m; j++) if (s[i][j] == '1')
			v.push_back(P(i, j, i - 1, j, i - 1, j + (j == m ? -1 : 1)));
		for (int i = m; i > 2; i--)
		{
			if (s[1][i] == '1' && s[2][i] == '1')
				v.push_back(P(1, i - 1, 1, i, 2, i));
			else if (s[1][i] == '1')
				v.push_back(P(1, i, 1, i - 1, 2, i - 1));
			else if (s[2][i] == '1')
				v.push_back(P(2, i, 1, i - 1, 2, i - 1));
		}

		if (get2x2() == 15) v.push_back(P(1, 1, 1, 2, 2, 1));
		if (get2x2() == 1) v.push_back(P(1, 1, 1, 2, 2, 2));
		if (get2x2() == 2) v.push_back(P(1, 1, 2, 1, 2, 2));
		if (get2x2() == 4) v.push_back(P(1, 1, 1, 2, 2, 2));
		if (get2x2() == 8) v.push_back(P(1, 1, 2, 1, 2, 2));
		if (get2x2() == 3) v.push_back(P(1, 1, 1, 2, 2, 1));
		if (get2x2() == 5) v.push_back(P(1, 1, 1, 2, 2, 1));
		if (get2x2() == 6) v.push_back(P(1, 1, 1, 2, 2, 2));
		if (get2x2() == 9) v.push_back(P(1, 1, 1, 2, 2, 1));
		if (get2x2() == 10) v.push_back(P(1, 1, 1, 2, 2, 2));
		if (get2x2() == 12) v.push_back(P(1, 1, 2, 1, 2, 2));
		if (get2x2() == 7) v.push_back(P(1, 2, 2, 1, 2, 2));
		if (get2x2() == 11) v.push_back(P(1, 1, 2, 1, 2, 2));
		if (get2x2() == 13) v.push_back(P(1, 1, 1, 2, 2, 2));
		if (get2x2() == 14) v.push_back(P(1, 1, 1, 2, 2, 1));

		printf("%lu\n", v.size());
		for (const P &i : v)
			for (int j = 0; j < 6; j++)
				printf("%d%c", i.a[j], " \n"[j == 5]);
	}
	return 0;
}
