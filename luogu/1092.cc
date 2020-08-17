#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>

using namespace std;

bool ch[200], nu[30];
char s[3][30];
int mp[200], n;

void print()
{
	for (int i = 0; i < n; i++)
	{
		printf("%d", mp[i + 'A']);
		putchar(i == n - 1 ? '\n' : ' ');
	}
	exit(0);
}

void debug()
{
	for (int i = 0; i < n; i++)
	{
		if (!ch[i + 'A'])
			putchar('X');
		else
			printf("%d", mp[i + 'A']);
		putchar(i == n - 1 ? '\n' : ' ');
	}
}

void dfs(int k, int c)
{
	if (k == -1)
	{
		if (c == 0)
			print();
		else
			return;
	}
	int mode = 0, fi[3];
	if (ch[s[0][k]]) 
	{
		mode += 4;
		fi[0] = mp[s[0][k]];
	}
	if (ch[s[1][k]]) 
	{
		mode += 2;
		fi[1] = mp[s[1][k]];
	}
	if (ch[s[2][k]]) 
	{
		mode += 1;
		fi[2] = mp[s[2][k]];
	}
	//cout << k << ' ';
	//cout << mode << endl;
//debug();
//cout << "        " << nu[0] << ' ' << nu[1] << ' ' << nu[2] << ' ' << nu[3] << endl;

	if (mode == 7)      // 111
	{
		if (fi[2] == (c + fi[0] + fi[1]) % n)
			dfs(k - 1, (c + fi[0] + fi[1]) / n);
		else
			return;
	}
	else if (mode == 6) // 110
	{
		//cout << "      " << s[0][k] << endl;
		//cout << "      " << c << " " << fi[0] << " " << fi[1] << " " << n << endl;
		fi[2] = (c + fi[0] + fi[1]) % n;
		//cout << "      " << fi[2] << endl;
		//cout << "     " << c << ' ' << fi[0] << ' ' << fi[1] << ' ' << fi[2] << endl;
		if (nu[fi[2]])
			return;
		nu[fi[2]] = true;
		ch[s[2][k]] = true;
		mp[s[2][k]] = fi[2];
		dfs(k - 1, (c + fi[0] + fi[1]) / n);
		ch[s[2][k]] = false;
		nu[fi[2]] = false;
	}
	else if (mode == 5) // 101
	{
		int t = fi[2] - c - fi[0];
		fi[1] = t < 0 ? t + n : t;
		//cout << "      " << fi[1] << ' ' << nu[1] << endl;
		if (nu[fi[1]])
			return;
		nu[fi[1]] = true;
		ch[s[1][k]] = true;
		mp[s[1][k]] = fi[1];
		//cout << "         "  << s[1][k] << "        " << mp[s[1][k]] << "      aaa" << endl;
		//dfs(k - 1, t < 0 ? 1 : 0);
		dfs(k - 1, (c + fi[0] + fi[1]) / n);
		ch[s[1][k]] = false;
		nu[fi[1]] = false;
	}
	else if (mode == 4) // 100
	{
		for (fi[1] = n - 1; fi[1] >= 0; fi[1]--)
		{
			if (nu[fi[1]])
				continue;
			nu[fi[1]] = true;
			ch[s[1][k]] = true;
			mp[s[1][k]] = fi[1];
			fi[2] = (c + fi[0] + fi[1]) % n;
			//if (fi[0] == 1)
				//cout << ' ' << ' ' << fi[1] << ' ' << ' ' << fi[2] << endl;
			if (!nu[fi[2]])
			{
				if (s[2][k] != s[1][k])
				{
					nu[fi[2]] = true;
					ch[s[2][k]] = true;
					mp[s[2][k]] = fi[2];
					dfs(k - 1, (c + fi[0] + fi[1]) / n);
					ch[s[2][k]] = false;
					nu[fi[2]] = false;
				}
			}
			else if (s[2][k] == s[1][k] && fi[2] == fi[1])
				dfs(k - 1, (c + fi[0] + fi[1]) / n);
			ch[s[1][k]] = false;
			nu[fi[1]] = false;
		}
	}
	else if (mode == 3) // 011
	{
		int t = fi[2] - c - fi[1];
		fi[0] = t < 0 ? t + n : t;
		if (nu[fi[0]])
			return;
		nu[fi[0]] = true;
		ch[s[0][k]] = true;
		mp[s[0][k]] = fi[0];
		//dfs(k - 1, t < 0 ? 1 : 0);
		dfs(k - 1, (c + fi[0] + fi[1]) / n);
		ch[s[0][k]] = false;
		nu[fi[0]] = false;
	}
	else if (mode == 2) // 010
	{
		for (fi[0] = n - 1; fi[0] >= 0; fi[0]--)
		{
			if (nu[fi[0]])
				continue;
			nu[fi[0]] = true;
			ch[s[0][k]] = true;
			mp[s[0][k]] = fi[0];
			fi[2] = (c + fi[0] + fi[1]) % n;
			if (!nu[fi[2]])
			{
				if (s[2][k] != s[0][k])
				{
					nu[fi[2]] = true;
					ch[s[2][k]] = true;
					mp[s[2][k]] = fi[2];
					dfs(k - 1, (c + fi[0] + fi[1]) / n);
					ch[s[2][k]] = false;
					nu[fi[2]] = false;
				}
			}
			else if (s[2][k] == s[0][k] && fi[2] == fi[0])
				dfs(k - 1, (c + fi[0] + fi[1]) / n);
			ch[s[0][k]] = false;
			nu[fi[0]] = false;
		}
	}
	else if (mode == 1) // 001
	{
		for (fi[0] = n - 1; fi[0] >= 0; fi[0]--)
		{
			if (nu[fi[0]])
				continue;
			nu[fi[0]] = true;
			ch[s[0][k]] = true;
			mp[s[0][k]] = fi[0];
			int t = fi[2] - c - fi[0];
			fi[1] = t < 0 ? t + n : t;
			if (!nu[fi[1]])
			{
				if (s[1][k] != s[0][k])
				{
					nu[fi[1]] = true;
					ch[s[1][k]] = true;
					mp[s[1][k]] = fi[1];
					//dfs(k - 1, t < 0 ? 1 : 0);
					dfs(k - 1, (c + fi[0] + fi[1]) / n);
					ch[s[1][k]] = false;
					nu[fi[1]] = false;
				}
			}
			else if (s[1][k] == s[0][k] && fi[1] == fi[0])
				//dfs(k - 1, t < 0 ? 1 : 0);
				dfs(k - 1, (c + fi[0] + fi[1]) / n);
			ch[s[0][k]] = false;
			nu[fi[0]] = false;
		}
	}
	else                // 000
	{
		for (fi[0] = n - 1; fi[0] >= 0; fi[0]--)
		{
			if (nu[fi[0]])
				continue;
			nu[fi[0]] = true;
			ch[s[0][k]] = true;
			mp[s[0][k]] = fi[0];
			if (s[1][k] == s[0][k])
			{
				fi[1] = fi[0];
				fi[2] = (c + fi[0] + fi[1]) % n;
				if (!nu[fi[2]])
				{
					if (s[2][k] != s[0][k])
					{
						nu[fi[2]] = true;
						ch[s[2][k]] = true;
						mp[s[2][k]] = fi[2];
						dfs(k - 1, (c + fi[0] + fi[1]) / n);
						ch[s[2][k]] = false;
						nu[fi[2]] = false;
					}
				}
				else if (s[2][k] == s[0][k] && fi[2] == fi[0])
					dfs(k - 1, (c + fi[0] + fi[1]) / n);
			}
			else
			{
				for (fi[1] = n - 1; fi[1] >= 0; fi[1]--)
				{
					if (nu[fi[1]])
						continue;
					nu[fi[1]] = true;
					ch[s[1][k]] = true;
					mp[s[1][k]] = fi[1];
					fi[2] = (c + fi[0] + fi[1]) % n;
					if (!nu[fi[2]])
					{
						if (s[2][k] != s[0][k] && s[2][k] != s[1][k])
						{
							nu[fi[2]] = true;
							ch[s[2][k]] = true;
							mp[s[2][k]] = fi[2];
							dfs(k - 1, (c + fi[0] + fi[1]) / n);
							ch[s[2][k]] = false;
							nu[fi[2]] = false;
						}
					}
					else if (s[2][k] == s[0][k] && fi[2] == fi[0])
						dfs(k - 1, (c + fi[0] + fi[1]) / n);
					else if (s[2][k] == s[1][k] && fi[2] == fi[1])
						dfs(k - 1, (c + fi[0] + fi[1]) / n);
					ch[s[1][k]] = false;
					nu[fi[1]] = false;
				}
			}
			ch[s[0][k]] = false;
			nu[fi[0]] = false;
		}
	}
}

int main()
{
	scanf("%d%s%s%s", &n, s[0], s[1], s[2]);
	dfs(n - 1, 0);
	return 0;
}
