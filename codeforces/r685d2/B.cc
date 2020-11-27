#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

char s[105], t[105][105];

bool p(int l0, int r0, int l1, int r1)
{
	int i = l0, j = l1;
	while (1)
	{
		if (i >= r0) return true;
		if (j >= r1) return false;
		if (s[i] == s[j]) i++;
		j++;
	}
}

bool check(int n)
{
	int l, r; scanf("%d%d", &l, &r); r++;
	for (int m = l + 1; m < r; m++) for (int k = 2; k < n; k++)
		if (p(l, m, 1, k) && p(m, r, k + 1, n + 1))
			return true;
	return false;
}

int main()
{
	int T; scanf("%d", &T);
	while (T--)
	{
		int n, q; scanf("%d%d%s", &n, &q, s + 1);
		while (q--) puts(check(n) ? "YES" : "NO");
	}
	return 0;
}
