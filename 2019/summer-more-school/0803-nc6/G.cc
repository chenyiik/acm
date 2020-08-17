#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <algorithm>

using namespace std;

const int maxn = int(1e5) + 5;
char _s[maxn][15], ans[15];
bool vis[15];
string s[maxn];
int n;

bool is_friday(char s[]);
bool _try(char c)
{
	if (c == 'K')
	{
		for (int i = 0; i < n; i++)
		{
			static char tmp[15];
			for (int j = 0; j < 10; j++)
				tmp[j] = s[i][j] == '/' ? '/' : ans[s[i][j] - 'A'];
			if (!is_friday(tmp))
				return false;
		}
		return true;
	}
	static const char *l = "1000X00X00", *r = "9999X19X39";
	char L = '0', R = '9';
	for (int k = 0; k < 5; k++)
	{
		int rr = rand() % n;
		for (int i = 0; i < 10; i++)
			if (s[rr][i] == c)
				L = max(L, l[i]), R = min(R, r[i]);
	}
	for (char i = L; i <= R; i++)
		if (!vis[i - '0'])
		{
			vis[i - '0'] = true;
			ans[c - 'A'] = i;
			if (_try(c + 1))
				return true;
			vis[i - '0'] = false;
		}
	return false;
}

int main()
{
	srand(time(NULL));
	int tn;
	scanf("%d", &tn);
	for (int cas = 1; cas <= tn; cas++)
	{
		memset(vis, 0, sizeof(vis));
		scanf("%d", &n);
		for (int i = 0; i < n; i++)
			scanf("%s", _s[i]), s[i] = string(_s[i]);
		sort(s, s + n);
		n = unique(s, s + n) - s;
		printf("Case #%d: %s\n", cas, _try('A') ? ans : "Impossible");
	}
	return 0;
}

bool is_friday(char s[])
{
	int Y, m, d;
	sscanf(s, "%d/%d/%d", &Y, &m, &d);
	static const int md[] = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	if (Y < 1600 || m == 0 || m > 12 || d == 0 || d > md[m])
		return false;
	if (m == 2 && d == 29 && !(Y % 400 == 0 || (Y % 100 != 0 && Y % 4 == 0)))
		return false;
	if (m < 3)
		m += 12, Y--;
	//int c = Y / 100, y = Y % 100;
	//int w = (y + y / 4 + c / 4 - 2 * c + (26 * (m + 1)) / 10 + d - 1) % 7;
	int y = Y;
	int w = (d + 2 * m + 3 * (m + 1) / 5 + y + y / 4 - y / 100 + y / 400 + 1) % 7;
	return w == 5;
}
