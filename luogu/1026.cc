#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int slen;

bool uni(const string &a, const string &b)
{
	if (a.size() > b.size())
		return false;
	for (int i = 0; i < a.size(); i++)
	{
		if (a[i] != b[i])
			return false;
	}
	return true;
}

void init(char s[], vector<string> &t, int n)
{
	while (n--)
	{
		scanf("%s", s + slen);
		slen += 20;
	}
	int k = 0;
	scanf("%d", &k);
	while (k--)
	{
		static char _s[250];
		scanf("%s", _s);
		t.push_back(string(_s));
	}
	sort(t.begin(), t.end());
	for (int i = 0; i < t.size() - 1; i++)
	{
		if (uni(t[i], t[i + 1]))
		{
			t.erase(t.begin() + i + 1);
			i--;
		}
	}
}

int f[205][205], g[45][205][205];
bool vis[45][205][205];

bool uni2(const string &t, const char sbe[], const char sen[])
{
	if (t.size() > sen - sbe)
		return false;
	for (int i = 0; i < t.size(); i++)
	{
		if (t[i] != sbe[i])
			return false;
	}
	return true;
}

void init2(const char s[], vector<string> &v)
{
	memset(f, 0, sizeof(0));
	for (int l = 0; l < slen; l++)
	{
		for (int r = l + 1; r <= slen; r++)
		{
			for (const auto &t : v)
			{
				for (int i = l; i < r; i++)
				{
					if (uni2(t, s + i, s + r))
						f[l][r]++;
				}
			}
		}
	}
	memcpy(g[0], f, sizeof(f));
	memset(vis, false, sizeof(vis));
	memset(vis[0], true, sizeof(vis[0]));
}

void show_f(const char s[]);
void show_g(const char s[], int sp);


int dfs(int sp, int l, int r)
{
	if (vis[sp][l][r])
		return g[sp][l][r];
	vis[sp][l][r] = true;
	int ans = 0;
	for (int k = l; k < r; k++)
	{
		for (int i = 0; i <= sp; i++)
		{
			int j = sp - i - 1;
			//if (i >= k - l || j >= r - k)
			if (i >= k - l || j >= r - k)
				continue;
			ans = max(ans, dfs(i, l, k) + dfs(j, k, r));
		}
	}
	return g[sp][l][r] = ans;
}

int main()
{
	for (int n = 0, m = 0; ~scanf("%d%d", &n, &m); slen = 0)
	{
		static char s[250];
		vector<string> v;
		init(s, v, n);
		//for (const string &i : v)
			//cout << i << endl;
		init2(s, v);
		//show_f(s);
		printf("%d\n", dfs(m - 1, 0, slen));
		//for (int i = 0; i <= m; i++)
		//{
			//cout << endl << i << endl;
			//show_g(s, i);
		//}
	}
	return 0;
}

void show_f(const char s[])
{
	cout << "  ";
	for (int i = 0; i < slen; i++)
		cout << s[i] << ' ';
	cout << endl;
	for (int i = 0; i < slen; i++)
	{
		cout << s[i] << ' ';
		for (int j = 1; j <= slen; j++)
			cout << f[i][j] << ' ';
		cout << endl;
	}
}

void show_g(const char s[], int sp)
{
	for (int i = 0; i < slen; i++)
	{
		for (int j = 1; j <= slen; j++)
			cout << g[sp][i][j] << ' ';
		cout << endl;
	}
}
