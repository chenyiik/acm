#include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int maxm = 10000 + 5;
vector<int> v[maxm];
int cnt[maxm];

int find(const vector<int> &,int l,int r);
int gcd(int a, int b) { return !b ? a : gcd(b, a % b); }
void fuck(int n, int l, int r, long long &ans)
{
	int m = (int)sqrt(n + 0.5), k = 0, p = 0;
	static int d[10], e[10];
	for (int i = 2; i <= m; i++)
		if (n % i == 0)
		{
			d[k++] = i;
			while (n % i == 0)
				n /= i;
		}
	if (n > 1)
		d[k++] = n;
	int f = 1;
	for (int i = 0; i < k; i++)
	{
		f *= d[i];
		ans -= find(v[d[i]], l, r);
		for (int j = i + 1; j < k; j++)
		{
			e[p] = d[i] * d[j];
			ans += find(v[e[p++]], l, r);
		}
	}
	if (k == 3)
		ans -= find(v[f], l, r);
	if (k == 4)
	{
		for (int i = 0; i < k; i++)
			ans -= find(v[f / d[i]], l, r);
		ans += find(v[f], l, r);
	}
	else if (k == 5)
	{
		for (int i = 0; i < p; i++)
			ans -= find(v[f / e[i]], l, r);
		for (int i = 0; i < k; i++)
			ans += find(v[f / d[i]], l, r);
		ans -= find(v[f], l, r);
	}
}

int main()
{
	for (int n; ~scanf("%d", &n); )
	{
		memset(cnt, 0, sizeof(cnt));
		for (int i = 0; i < maxm; i++) v[i].clear();
		for (int i = 0; i < n; i++)
		{
			int x; scanf("%d", &x);
			if (!cnt[x]++)
				for (int i = 1; i <= x; i++) if (x % i == 0)
					v[i].push_back(x);
		}
		for (int i = 0; i < maxm; i++) sort(v[i].begin(), v[i].end());
		const vector<int> &a = v[1];
		long long ans = 0;
		for (int i : a) for (int j : a)
		{
			if (cnt[j] < 2 || (i == j && cnt[j] < 3))
				continue;
			int l = i, r = i + 2 * j;
			ans += find(a, l, r);
			int g = gcd(i, j);
			if (g == 1)
			{
				if (i < j && cnt[j] < 3)
					ans--;
			}
			else
				fuck(g, l, r, ans);
		}
		printf("%lld\n", ans);
	}
	return 0;
}

int find(const vector<int>& a,int l,int r)
{
    int s1=upper_bound(a.begin(),a.end(),l)-a.begin();
    int s2=lower_bound(a.begin(),a.end(),r,less<int>())-a.begin();
    return s2-s1;
}
