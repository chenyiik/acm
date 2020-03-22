#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

typedef pair<int, int> PII;

char mp[105][105], a[105][105], b[105][105];
const int mv[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
const PII cpii = make_pair(-1, -1);
int n, m;

void check_ten(int x, int y);
void edge(PII st, char c);
int draw(char v[][105], char c);

int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++)
		scanf("%s", mp[i]);
	PII posA, posB;
	for (int i = 0; i < n; i++) for (int j = 0; j < m; j++)
	{
		if (mp[i][j] == 'A') posA = make_pair(i, j);
		else if (mp[i][j] == 'B') posB = make_pair(i, j);
		check_ten(i, j);
	}
	edge(posA, 'A'), edge(posB, 'B');
	draw(a, 'A'), draw(b, 'B');
	//for (int i = 0; i < n; i++) printf("%s\n", mp[i]);
	return 0;
}

void bfs(char v[][105], int x, int y, int c)
{
	if (v[x][y] == 'F')
		return;
	v[x][y] = 'F';
	queue<PII> Q;
	Q.push(make_pair(x, y));
	while (!Q.empty())
	{
		PII = Q.front(); Q.pop();
		
	}
}

int draw(char v[][105], char c)
{
	for (int i = 0; i < n; i++)
	{
		if (mp[i][0] != c) bfs(v, i, 0, c);
		if (mp[i][m - 1] != c) bfs(v, i, m - 1, c);
	}
	for (int j = 0; j < m; j++)
	{
		if (mp[0][j] != c) bfs(v, 0, j, c);
		if (mp[n - 1][j] != c) bfs(v, n - 1, j, c);
	}
	for (int i = 0; i < n; i++) for (int j = 0; j < m; j++)
		if (mp[i][j] == c || mp[i][j] == '+')
			v[i][j] = 'M';
		else if (v[i][j] != 'F')
			v[i][j] = 'T';
	return 0;
}

PII find_nxt(PII pre, PII st, char ch)
{
	//cout << pre.first << ' ' << pre.second << '\t';
	//cout << st.first << ' ' << st.second << '\t';
	PII nxt = cpii;
	if (mp[st.first][st.second] == '+')
	{
		 nxt = make_pair(2 * st.first - pre.first,
				2 * st.second - pre.second);
	}
	else for (int i = 0; i < 4; i++)
	{
		int dx = st.first + mv[i][0], dy = st.second + mv[i][1];
		if (dx < 0 && dx >= n && dy < 0 && dy >= m)
			continue;
		nxt = make_pair(dx, dy); 
		if (pre == nxt)
		{
			nxt = cpii;
			continue;
		}
		char &c = mp[dx][dy];
		if (c == 'X' || c == '+')
			break;
		nxt = cpii;
	}
	char &c = mp[nxt.first][nxt.second];
	//cout << nxt.first << ' ' << nxt.second << endl;
	if (nxt == cpii || c == '+') return nxt;
	else return c = ch, nxt;
}

void edge(PII st, char c)
{
	//int i = 0;
	for (PII pre = cpii; ; )
			//i < 20; i++)
	{
		PII nxt = find_nxt(pre, st, c);
		if (nxt == cpii)
			break;
		pre = st, st = nxt;
	}
}

void check_ten(int x, int y)
{
	int tot = 0;
	for (int i = 0; i < 4; i++)
	{
		int dx = x + mv[i][0], dy = y + mv[i][1];
		if (dx < 0 || dx >= n || dy < 0 || dy >= m)
			continue;
		char &c = mp[dx][dy];
		if (c != '.')
			tot++;
	}
	if (tot == 4 && mp[x][y] == 'X')
		mp[x][y] = '+';
}
