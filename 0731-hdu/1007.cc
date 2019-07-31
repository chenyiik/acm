#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <set>
#include <queue>
#include <unordered_set>

using namespace std;

typedef long long LL;
typedef unsigned long long ULL;

struct P { int step; ULL status; int pos;};

unordered_set<ULL> S;

ULL a[4][4];
const int mv[4] = {-4, -1, 4, 1};

void init()
{
	ULL s = 0x123456789ABCDEF0LL;
	queue<P> Q;
	Q.push(P{0, s, 15});
	S.insert(s);
	while (!Q.empty())
	{
		//cout << Q.size() << endl;
		P u = Q.front(); Q.pop();
//if (u.step < 3) 
	printf("%d %llx\n", u.step, u.status);
		if (u.step == 30)
			continue;
		for (int i = 0; i < 4; i++)
		{
			if ((i == 0 && u.pos < 4) || (i == 1 && u.pos % 4 == 0)
					|| (i == 2 && u.pos >= 12) || (i == 3 && u.pos % 4 == 3))
				continue;
			P t = u;
			t.pos += mv[i], t.step++;
			int xb = (15 - u.pos) * 4, yb = (15 - t.pos) * 4;
			t.status &= ~(15ULL << xb) & ~(15ULL << yb);
			if (xb < yb)
				swap(xb, yb);
			ULL x = u.status & (15ULL << xb), y = u.status & (15ULL << yb);
			x >>= abs(mv[i] * 4), y <<= abs(mv[i] * 4);
			t.status |= x | y;
			if (S.find(t.status) == S.end())
				Q.push(t), S.insert(t.status);
		}
	}
}

int main()
{
	init();
	cout << S.size() << endl;
	int t;
	scanf("%d", &t);
	while (t--)
	{
	}
	return 0;
}
