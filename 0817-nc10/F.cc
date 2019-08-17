#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int maxn = int(1e5) + 5;
struct P { int x, y; } a[maxn];

const int maxN = 400000 + 20;
const int oo = 0x7fffffff;
int maxv[maxN];

int ql, qr;

int query(int o, int L, int R) //get max in [ql, qr]
{
	int M = L + (R - L) / 2, ans = -oo;
	if (ql <= L && R <= qr)
		return maxv[o];
	if (ql <= M)
		ans = max(ans, query(o * 2, L, M));
	if (M < qr)
		ans = max(ans, query(o * 2 + 1, M + 1, R));
	return ans;
}

int p, v;

void update(int o, int L, int R) //let A[p] = v;
{
	int M = L + (R - L) / 2;
	if (L == R)
		maxv[o] += v;
	else
	{
		if (p <= M)
			update(o * 2, L, M);
		else
			update(o * 2 + 1, M + 1, R);
		maxv[o] = max(maxv[o * 2], maxv[o * 2 + 1]);
	}
}

int sum[maxn];
vector<int> vec[maxn];

int main()
{
	int n, r; scanf("%d%d", &n, &r);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d%d", &a[i].x, &a[i].y);
		a[i].x++, a[i].y++;
		for (int j = 0; j <= 2 && a[i].x - j * r > 0; j++)
		{
			sum[a[i].x - j * r]++;
			//vec[a[i].x - j * r].push_back(a[i].y);
			//cout << a[i].x - j * r << ' ' << a[i].y << endl;
		}
		for (int j = 0; j <= 2 && a[i].y - j * r > 0; j++)
		{
			p = a[i].y - j * r, v = 1, update(1, 1, maxn - 2);
			vec[a[i].x].push_back(a[i].y - j * r);
			//cout << p << endl;
		}
	}
	//sort(a, a + n, [](P a, P b){return a.x < b.x;});
	/*
	for (int i = 1; i <= 10; i++)
	{
		cout << i << ':';
		for (int j : vec[i])
			cout << j << ' ';
		cout << endl;
	}
	*/
	int ans = 0;
	for (int i = 1; i <= maxn - 2; i++)
	{
		for (int k = 0; k <= 2 && i + k * r <= maxn - 2; k++)
			for (int j : vec[i + k * r])
				p = j, v = -1, update(1, 1, maxn - 2);
		ql = 1, qr = maxn - 2;
		ans = max(ans, sum[i] + query(1, 1, maxn - 2));
		//if (i < 20)
			//cout << i << ' ' << sum[i] << ' ' << query(1, 1, maxn - 2) << endl;
		for (int k = 0; k <= 2 && i + k * r <= maxn - 2; k++)
			for (int j : vec[i + k * r])
				p = j, v = 1, update(1, 1, maxn - 2);
		
	}
	printf("%d\n", ans);
	return 0;
}
