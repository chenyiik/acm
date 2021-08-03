#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <queue>
#include <utility>
#include <unordered_map>
#include <unordered_set>

using namespace std;

const int base[9] = { 1, 10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000};
const int mv[6][3] = {{8, 7, 6}, {5, 4, 3}, {2, 1, 0}, {8, 5, 2}, {7, 4, 1}, {6, 3, 0}};

int get_bit(int n, int b) { return n / base[b] % 10; } 
void set_bit(int &n, int b, int x) { n = n - get_bit(n, b) * base[b] + x * base[b]; }

int main()
{
	unordered_map<int, int> M; M[987654321] = 0;
	queue<int> Q; Q.push(987654321);
	while (!Q.empty())
	{
		int u = Q.front(), step = M[u]; Q.pop();
		for (int i = 0; i < 6; i++)
		{
			int v = u, a = get_bit(v, mv[i][0]), b = get_bit(v, mv[i][1]), c = get_bit(v, mv[i][2]);
			set_bit(v, mv[i][0], c); set_bit(v, mv[i][1], a); set_bit(v, mv[i][2], b);
			if (M.find(v) == M.end())
				M[v] = step + 1, Q.push(v);
		}
	}
	int _; scanf("%d", &_);
	while (_--)
	{
		int l11, l12, l13, l21, l22, l23; scanf("%d%d%d%d%d%d", &l11, &l12, &l13, &l21, &l22, &l23);
		int s = l11 * int(1e6) + l12 * int(1e3) + l13, t = l21 * int(1e6) + l22 * int(1e3) + l23, k = 0;
		for (int i = 0; i < 9; i++) for (int j = 0; j < 9; j++)
			if (get_bit(s, i) == get_bit(t, j)) set_bit(k, j, i + 1);
		if (M.find(k) == M.end()) puts("impossible");
		else printf("%d\n", M[k]);
	}
	return 0;
}
