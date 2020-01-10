#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <map>
#include <vector>

using namespace std;


char stmp[1500];
bool read() { return fgets(stmp, 1200, stdin) != NULL && stmp[0] != '\n'; }
int dfs(int [], const vector<int> (&)[1005], const bool [], int);

int main()
{
	read();
	int t = 0;
	sscanf(stmp, "%d", &t);
	read();
	for (int Case = 1; Case <= t; Case++)
	{
		vector<int> v[1005];
		map<string, int> M;
		static bool b[1005];
		memset(b, false, sizeof(b));
		int n = 0;
		while (read())
		{
			static char st[1200];
			int q = 0;
			sscanf(stmp, "%s%n", st, &q);
			int la = strlen(st);
			st[--la] = '\0';
			bool bb = false;
			if (st[la - 1] == '*')
			{
				bb = true;
				st[--la] = '\0';
			}
			if (M.find(st) == M.end())
				M[st] = n++;
			int i = M[st];
			b[i] = bb;
			for (int p = q; ~sscanf(stmp + p, "%s%n", st, &q); p += q)
			{
				if (M.find(st) == M.end())
					M[st] = n++;
				v[i].push_back(M[st]);
			}
		}
		static int f[1005];
		memset(f, -1, sizeof(f));
		int ans = 0;
		for (int i = 0; i < n; i++)
			ans = max(ans, dfs(f, v, b, i));
		//for (int i = 0; i < n; i++)
			//cout << f[i] << endl;
		//for (auto i : M)
			//cout << i.first << '\t' << f[i.second] << endl;
		printf("Case %d: %d\n", Case, ans);
	}
	return 0;
}

int dfs(int f[], const vector<int> (&v)[1005], const bool b[], int u)
{
	if (~f[u])
		return f[u];
	f[u] = 0;
	for (auto i : v[u])
		f[u] = max(f[u], dfs(f, v, b, i));
	if (b[u])
		f[u]++;
	return f[u];
}
