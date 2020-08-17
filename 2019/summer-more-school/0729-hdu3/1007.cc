#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std; 

typedef long long LL;

const int maxn = int(4e5) + 5;
LL C[maxn], D[maxn];
int n;
int lowbit(int x) { return x & -x; }

void add0(int x, LL d) { while (x <= n) { C[x] += d; x += lowbit(x); } }
LL sum0(int x) { LL ret = 0; while (x > 0) { ret += C[x]; x -= lowbit(x); } return ret; }

void add1(int x, LL d = 1) { while (x <= n) { D[x] += d; x += lowbit(x); } }
LL sum1(int x) { LL ret = 0; while (x > 0) { ret += D[x]; x -= lowbit(x); } return ret; }

struct P { LL v; int p, d; } a[maxn];

int find(LL k)
{
	int L = 0, R = n + 1;
	//cout << k << endl;
	while (L + 1 < R)
	{
		int mid = (L + R) / 2;
		LL tot = sum0(mid);
		//cout << L << ' ' << R << ' ' << mid << ' ' << tot << endl;
		if (tot <= k)
			L = mid;//, cout << "L=" << L << endl;
		else
			R = mid;//, cout << "R=" << R << endl;
	}
	//cout << endl;
	//return sum0(L) > k ? L - 1 : L;
	return L;
}

int main()
{
	int t;
	scanf("%d", &t);
	while (t--)
	{
		memset(C, 0, sizeof(C));
		memset(D, 0, sizeof(D));
		LL m;
		scanf("%d%lld", &n, &m);
		for (int i = 1; i <= n; i++)
			scanf("%lld", &a[i].v), a[i].d = i;
		sort(a + 1, a + 1 + n, [](P a, P b) { return a.v < b.v; });
		for (int i = 1; i <= n; i++)
			a[i].p = i;
		sort(a + 1, a + 1 + n, [](P a, P b) { return a.d < b.d; });
		for (int i = 1; i <= n; i++)
		{
			LL k = m - a[i].v;
			int t = sum1(find(k));
			//printf("%d%c", i - t - 1, " \n"[i == n]);
			printf("%d ", i - t - 1);
			add0(a[i].p, a[i].v);
			add1(a[i].p);
		}
		puts("");
	}
	return 0;
}
