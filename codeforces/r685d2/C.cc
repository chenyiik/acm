#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int maxn = int(1e6) + 5;
char s[maxn], t[maxn];
int a[256], b[256];

bool check(int n, int k)
{
	memset(a, 0, sizeof(a));
	memset(b, 0, sizeof(b));
	for (int i = 0; i < n; i++)
		a[s[i]]++, b[t[i]]++;
	for (char c = 'a'; c <= 'z'; c++)
	{
		int d = a[c] - b[c];
		if (d < 0 || d % k > 0) return false;
		a[c + 1] += d;
	}
	return true;
}

int main()
{
	int T; scanf("%d", &T);
	while (T--)
	{
		int n, k; scanf("%d%d%s%s", &n, &k, s, t);
		puts(check(n, k) ? "Yes" : "No");
	}
	return 0;
}
