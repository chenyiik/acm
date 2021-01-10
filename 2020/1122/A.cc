#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int maxn = int(1e5) + 10;
char s[maxn], t[maxn];

int dfs(const char *s, const char *const se, const char *t, const char *const te, int cnt)
{
	if (cnt > 3) return cnt;
	while (s < se && t < te && *s == *t) s++, t++;
	if (s >= se && t >= te) return cnt;
	return min(min(dfs(s + 1, se, t, te, cnt + 1), dfs(s, se, t + 1, te, cnt + 1)), dfs(s + 1, se, t + 1, te, cnt + 1));
}

int main()
{
	int T; scanf("%d", &T);
	while (T--)
	{
		scanf("%s%s", s, t);
		int sn = strlen(s), tn = strlen(t);
		int ans = dfs(s, s + sn, t, t + tn, 0);
		if (ans == 0) puts("You're logged in!");
		else if (ans == 1) puts("You almost got it. You're wrong in just one spot.");
		else if (ans == 2) puts("You almost got it, but you're wrong in two spots.");
		else if (ans == 3) puts("You're wrong in three spots.");
		else puts("What you entered is too different from the real password.");
	}
	return 0;
}
