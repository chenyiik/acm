#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int maxn = int(1e5) + 5;
char s[maxn];
char t[maxn * 4], p[maxn * 4];

char build(int o, int L, int R);
char set(int o, int L, int R, int l, int r, char v);
char query(int o, int L, int R, int l, int r);

void solve()
{
	int n, q; scanf("%d%d%s", &n, &q, s);
	build(1, 0, n);
	//for (int i = 1; i < 20; i++) putchar(t[i] ? t[i] : ' ');
	for (int i = 0; i < q; i++)
	{
		int op; scanf("%d", &op);
		if (op == 1)
		{
			int l, r; char c; scanf("%d%d %c", &l, &r, &c);
			set(1, 0, n, l - 1, r, c);
		}
		else
		{
			int l, r; scanf("%d%d", &l, &r);
			printf("%c\n", query(1, 0, n, l - 1, r));
		}
	}
}

char f(char a, char b);

char set(int o, int L, int R, int l, int r, char v)
{
	int mid = (L + R) / 2;
	if (l == L && r == R)
	{
		return p[o] = v;
	}
	else if (r <= mid)
	{
		if (p[o] != '0') p[o * 2] = p[o], p[o * 2 + 1] = p[o], p[o] = '0';
		char a = set(o * 2, L, mid, l, r, v);
		t[o] = f(a, p[o * 2 + 1] == '0' ? t[o * 2 + 1] : p[o * 2 + 1]);
	}
	else if (l >= mid)
	{
		if (p[o] != '0') p[o * 2] = p[o], p[o * 2 + 1] = p[o], p[o] = '0';
		char b = set(o * 2 + 1, mid, R, l, r, v);
		t[o] = f(p[o * 2] == '0' ? t[o * 2] : p[o * 2], b);
	}
	else
	{
		if (p[o] != '0') p[o * 2] = p[o], p[o * 2 + 1] = p[o], p[o] = '0';
		char a = set(o * 2, L, mid, l, mid, v);
		char b = set(o * 2 + 1, mid, R, mid, r, v);
		t[o] = f(a, b);
	}
	return t[o];
}

char query(int o, int L, int R, int l, int r)
{
	int mid = (L + R) / 2;
	if (l == L && r == R)
	{
		return p[o] == '0' ? t[o] : p[o];
	}
	else if (r <= mid)
	{
		if (p[o] != '0') p[o * 2] = p[o], p[o * 2 + 1] = p[o], p[o] = '0';
		return query(o * 2, L, mid, l, r);
	}
	else if (l >= mid)
	{
		if (p[o] != '0') p[o * 2] = p[o], p[o * 2 + 1] = p[o], p[o] = '0';
		return query(o * 2 + 1, mid, R, l, r);
	}
	else
	{
		if (p[o] != '0') p[o * 2] = p[o], p[o * 2 + 1] = p[o], p[o] = '0';
		char a = query(o * 2, L, mid, l, mid);
		char b = query(o * 2 + 1, mid, R, mid, r);
		return f(a, b);
	}
}

char build(int o, int L, int R)
{
	int mid = (L + R) / 2;
	if (L + 1 == R)
	{
		t[o] = s[L];
	}
	else
	{
		char a = build(o * 2, L, mid);
		char b = build(o * 2 + 1, mid, R);
		t[o] = f(a, b);
	}
	p[o] = '0';
	return t[o];
}

char f(char a, char b)
{
	int x, y;
	if (a == 'r') x = 0; if (a == 'y') x = 1; if (a == 'b') x = 2;
	if (a == 'o') x = 3; if (a == 'p') x = 4; if (a == 'g') x = 5;
	if (a == 'x') x = 6;
	if (b == 'r') y = 0; if (b == 'y') y = 1; if (b == 'b') y = 2;
	if (b == 'o') y = 3; if (b == 'p') y = 4; if (b == 'g') y = 5;
	if (b == 'x') y = 6;
	static const char mp[7][8] = {
		{ "ropopxx" },
		{ "oygoxgx" },
		{ "pgbxpgx" },
		{ "ryxopgx" },
		{ "rxbopgx" },
		{ "xybopgx" },
		{ "rybopgx" }};
	return mp[x][y];
}

int main()
{
	int _; scanf("%d", &_);
	while (_--) solve();
	return 0;
}
