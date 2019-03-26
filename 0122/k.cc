#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct P
{
	char *s;
	bool c[30];
};

P a[100005];
vector<int> v[100005];

bool f(const P &r, const P &t)
{
	int p = strlen(r.s);
	for (p--; p >= 0; p--)
	{
		if (!t.c[r.s[p] - 'a'])
			break;
	}
	if (p >= 0)
	{
		int q = strlen(t.s) - 1;
		while (p >= 0 && q >= 0)
		{
			if (r.s[p] == t.s[q])
				p--;
			q--;
		}
	}
	return p < 0;
}

int main()
{
	int n = 0;
	static char st[1000005];
	fgets(st, 1000, stdin);
	sscanf(st, "%d", &n);
	for (int i = 1; i <= n; i++)
	{
		fgets(st, 1000003, stdin);
		char *p = strchr(st, ' ');
		int len = p - st;
		a[i].s = new char[len + 5];
		strncpy(a[i].s, st, len);
		for (++p; *p != '\0'; p++)
		{
			if (*p == '\n')
				continue;
			a[i].c[*p - 'a'] = 1;
		}
	}
	int m = 0;
	v[m++].push_back(1);
	for (int i = 2; i <= n; i++)
	{
		int b = false;
		for (int j = 0; j < m; j++)
		{
			P &t = a[v[j][0]];
			if (memcmp(a[i].c, t.c, sizeof(bool) * 26) != 0)
				continue;
			int p = strlen(a[i].s) - 1, q = strlen(t.s) - 1;
			while (p >= 0 && t.c[a[i].s[p] - 'a'])
				p--;
			while (q >= 0 && a[i].c[t.s[q] - 'a'])
				q--;
			//if (f(a[i], t) && f(t, a[i]))
			//cout << p << ' ' << q << endl;
			if (p == q && strncmp(a[i].s, t.s, p + 1) == 0)
			{
				b = true;
				v[j].push_back(i);
				break;
			}
		}
		if (!b)
			v[m++].push_back(i);
	}
	printf("%d\n", m);
	for (int i = 0; i < m; i++)
	{
		printf("%d ", v[i].size());
		for (int j = 0; j < v[i].size(); j++)
			printf("%d ", v[i][j]);
		puts("");
	}
	return 0;
}
