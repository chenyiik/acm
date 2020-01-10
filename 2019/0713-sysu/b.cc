#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	int n;
	scanf("%d", &n);
	const int maxn = int(2e5) + 5;
	static char s[maxn];
	scanf("%s", s);
	static vector<int> v[30];
	for (int i = 0; i < n; i++)
		v[s[i] - 'a'].push_back(i);
	int m;
	scanf("%d", &m);
	while (m--)
	{
		scanf("%s", s);
		static int cnt[30];
		memset(cnt, -1, sizeof(cnt));
		for (char *p = s; *p != 0; p++)
			cnt[*p - 'a']++;
		int ans = -1;
		for (int i = 0; i < 26; i++)
			if (cnt[i] >= 0)
				ans = max(ans, v[i][cnt[i]]);
		printf("%d\n", ans + 1);
	}
	return 0;
}
