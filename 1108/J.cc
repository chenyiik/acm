#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <utility>

using namespace std;

unsigned g2u(const char *s);
char u2c(unsigned n, int x, int y);
unsigned set(unsigned n, int x, int y, char ch);
bool empty(unsigned n);
int score(unsigned n);

int f[2][int(1e6)];
unsigned g[2][int(1e6)];

pair<int, unsigned> dfs(unsigned cur, int h)
{
	printf("%x\n", cur);
	if (f[h][cur] < 114514)
		return make_pair(f[h][cur], g[h][cur]);
	if (!empty(cur))
		return make_pair(f[h][cur] = score(cur), g[h][cur] = cur);
	int ans = h == 1 ? -114514 : 114514;
	unsigned nxt;
	for (int i = 0; i < 3; i++) for (int j = 0; j < 3; j++)
	{
		if (u2c(cur, i, j) != '.') continue;
		cout << h << i << j << endl;
		unsigned tmp = set(cur, i, j, h == 1 ? '0' : 'X');
		pair<int, unsigned> p = dfs(tmp, h ^ 1);
		if ((h == 1 && p.first > ans) || (h == 0 && p.first < ans))
			ans = p.first, nxt = tmp;
	printf("\t%x\n", tmp);
	}
	return make_pair(f[h][cur] = ans, g[h][cur] = nxt);
}

int main()
{
	for (int i = 0; i < int(1e6); i++)
		f[0][i] = f[1][i] = 114514;
	int _; scanf("%d", &_);
	while (_--)
	{
		int h; scanf("%d", &h);
		char s[15];
		for (int i = 0; i < 3; i++)
			scanf("%s", s + i * 3);
		unsigned cur = g2u(s);
		while (empty(cur))
		{
			cur = dfs(cur, h).second;
	printf("%x\n", cur);
			h ^= 1;
		}
		printf("%d\n", score(cur));
	}
	return 0;
}

unsigned c2u(char ch)
{
	if (ch == '0') return 3;
	else if (ch == 'X') return 2;
	else return 0;
}

char u2c(unsigned n)
{
	if (n == 3) return '0';
	else if (n == 2) return 'X';
	else return '.';
}

unsigned g2u(const char *s)
{
	unsigned ret = 0;
	for (int i = 0; i < 9; i++)
	{
		ret <<= 2;
		ret |= c2u(s[i]);
	}
	return ret;
}

char u2c(unsigned n, int x, int y)
{
	int pos = x * 3 + y;
	n >>= (8 - pos) * 2;
	n &= 3;
	return u2c(n);
} 

unsigned set(unsigned n, int x, int y, char ch)
{
	int pos = x * 3 + y;
	unsigned v = ch == 'X' ? 2 : 3;
	n &= ~(3u << ((8 - pos) * 2));
	n |= v << ((8 - pos) * 2);
	return n;
}

bool empty(unsigned n)
{
	for (int i = 0; i < 3; i++) for (int j = 0; j < 3; j++)
		if (u2c(n, i, j) == '0')
			return true;
	return false;
}

int score(unsigned n)
{
	int ans = 0;
	if (u2c(n, 0, 0) == '0' && u2c(n, 0, 1) == '0' && u2c(n, 0, 2) == '0') ans++;
	if (u2c(n, 1, 0) == '0' && u2c(n, 1, 1) == '0' && u2c(n, 1, 2) == '0') ans++;
	if (u2c(n, 2, 0) == '0' && u2c(n, 2, 1) == '0' && u2c(n, 2, 2) == '0') ans++;
	if (u2c(n, 0, 0) == '0' && u2c(n, 1, 0) == '0' && u2c(n, 2, 0) == '0') ans++;
	if (u2c(n, 0, 1) == '0' && u2c(n, 1, 1) == '0' && u2c(n, 2, 1) == '0') ans++;
	if (u2c(n, 0, 2) == '0' && u2c(n, 1, 2) == '0' && u2c(n, 2, 2) == '0') ans++;
	if (u2c(n, 0, 0) == '0' && u2c(n, 1, 1) == '0' && u2c(n, 2, 2) == '0') ans++;
	if (u2c(n, 0, 2) == '0' && u2c(n, 1, 1) == '0' && u2c(n, 2, 0) == '0') ans++;

	if (u2c(n, 0, 0) == 'X' && u2c(n, 0, 1) == 'X' && u2c(n, 0, 2) == 'X') ans--;
	if (u2c(n, 1, 0) == 'X' && u2c(n, 1, 1) == 'X' && u2c(n, 1, 2) == 'X') ans--;
	if (u2c(n, 2, 0) == 'X' && u2c(n, 2, 1) == 'X' && u2c(n, 2, 2) == 'X') ans--;
	if (u2c(n, 0, 0) == 'X' && u2c(n, 1, 0) == 'X' && u2c(n, 2, 0) == 'X') ans--;
	if (u2c(n, 0, 1) == 'X' && u2c(n, 1, 1) == 'X' && u2c(n, 2, 1) == 'X') ans--;
	if (u2c(n, 0, 2) == 'X' && u2c(n, 1, 2) == 'X' && u2c(n, 2, 2) == 'X') ans--;
	if (u2c(n, 0, 0) == 'X' && u2c(n, 1, 1) == 'X' && u2c(n, 2, 2) == 'X') ans--;
	if (u2c(n, 0, 2) == 'X' && u2c(n, 1, 1) == 'X' && u2c(n, 2, 0) == 'X') ans--;
	return ans;
}
