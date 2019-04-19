#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

typedef long long LL;

const int N = 500005 * 20;
LL a[N], L[N], R[N];
bool vis[N];

struct P
{
	LL value;
	int pos;
	bool operator<(const P &o) const 
	{ 
		return value < o.value 
			|| (value == o.value && pos < o.pos);
	}
};

int main()
{
	int n = 0, k = 0;
	scanf("%d%d", &n, &k);
	priority_queue<P> Q;
	for (int i = 0; i < n; i++)
	{
		scanf("%lld", &a[i]);
		Q.push({a[i], i});
		L[i] = i - 1, R[i] = i + 1;
	}
	LL ans = 0;
	while (k--)
	{
		while (!Q.empty() && vis[Q.top().pos])
		{
#ifdef _D
			cout << Q.top().value << ' ' << Q.top().pos << endl;
#endif
			Q.pop();
		}
		if (Q.empty() || Q.top().value <= 0)
			break;
		P p = Q.top();
		Q.pop();
		ans += p.value;
#ifdef _D
		cout << L[p.pos] << ' ' << p.pos << ' ' << R[p.pos] << endl;
#endif
		vis[p.pos] = true;
		P q;
		q.value = -p.value;
		q.pos = ++n;
		if (L[p.pos] != -1)
		{
			vis[L[p.pos]] = true;
			q.value += a[L[p.pos]];
			L[q.pos] = L[L[p.pos]];
			if (L[q.pos] != -1)
				R[L[q.pos]] = q.pos;
		}
		if (R[p.pos] != n)
		{
			vis[R[p.pos]] = true;
			q.value += a[R[p.pos]];
			R[q.pos] = R[R[p.pos]];
			if (R[q.pos] != n)
				L[R[q.pos]] = q.pos;
		}
		if (L[p.pos] == -1 || R[p.pos] == n)
			continue;
		Q.push(q);
		a[q.pos] = q.value;
	}
	printf("%lld\n", ans);
	return 0;
}
