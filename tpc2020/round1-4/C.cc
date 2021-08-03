#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int maxn = int(2e5) + 5;
struct P 
{
	int value, index;
	bool tag;
} a[maxn];

bool cmp(const P &a, const P &b) { return a.value > b.value; }
bool cmq(const P &a, const P &b) { return a.index < b.index; }

int main()
{
	int _; scanf("%d", &_);
	while (_--)
	{
		int n; scanf("%d", &n);
		for (int i = 0; i < n; i++)
		{
			scanf("%d", &a[i].value);
			a[i].index = i;
		}
		sort(a, a + n, cmp);
		int L = 0, R = 0;
		for (int i = 0; i < n; i++)
		{
			if (L <= R)
				L += a[i].value, a[i].tag = true;
			else
				R += a[i].value, a[i].tag = false;
		}
		sort(a, a + n, cmq);
		for (int i = 0; i < n; i++)
			putchar(a[i].tag ? 'a' : 'b');
		puts("");
	}
	return 0;
}
