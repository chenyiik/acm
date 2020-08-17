#include <cstdio>
#include <map>

using namespace std;

const int a[][2]{{-2, -1}, {-2, 1}, {-1, -2}, {-1, 2}, {1, -2}, {1, 2}, {2, -1}, {2, 1}};
void r(int &v, int d, int b) { b ? v |= 1 << d : v &= ~(1 << d); }
void r(int &v, int d) { r(v, d, 0), (v &= (1 << 25) - 1) |= d << 25; }
int m(int v, int p, int q) { r(v, p, v & (1 << q)), r(v, q); return v; }

int g(int v, const int a[2])
{
	int x = (v >> 25) / 5 + a[0], y = (v >> 25) % 5 + a[1], z = a[0] * 5 + a[1];
	return x < 0 || x > 4 || y < 0 || y > 4 ? 0 : m(v, v >> 25, (v >> 25) + z);
}

int make(map<int, int> &S, int s, const map<int, int> &T = map<int, int>())
{
	static int Q[100000], f, b;
	Q[b = 0] = s, f = -1, S[s] = 0, S[0] = -1;
	while (S[Q[++f]] <= 7 && T.find(Q[f]) == T.end())
		for (auto i : a)
			if (S.find(g(Q[f], i)) == S.end())
				Q[++b] = g(Q[f], i), S[g(Q[f], i)] = S[Q[f]] + 1;
	return T.find(Q[f]) == T.end() ? -1 : S[Q[f]] + T.find(Q[f])->second;
}

int main()
{
	map<int, int> T;
	make(T, 03002061737);
	int t;
	scanf("%d", &t);
	while (t--)
	{
		char st[26];
		for (int i = 0; i < 25; i += 5)
			scanf("%s", st + i);
		int s = 0;
		for (int i = 0; i < 25; i++)
			st[i] == '*' ? r(s, i) : r(s, i, st[i] - '0');
		map<int, int> S;
		printf("%d\n", make(S, s, T));
	}
	return 0;
}
