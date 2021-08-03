#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <set>
#include <vector>

using namespace std;

const int maxn = int(1e5) + 5;
int a[maxn], b[maxn];
bool c[maxn];
int p[maxn];

void solve()
{
	int n; scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%d", &a[i]);
	for (int i = 0; i < n; i++) scanf("%d", &b[i]);
	if (a[0] != b[0]) { puts("No"); return; }
	int tot = 0;
	vector<int> v;
	set<int> S;
	v.push_back(0);
	for (int i = 0; i < n; i++)
	{
		set<int>::iterator it = S.find(a[i]);
		if (it == S.end()) c[a[i]] = true, tot++;
		else S.erase(it);
		if (c[b[i]]) c[b[i]] = false, tot--;
		else S.insert(b[i]);
		if (tot == 0) v.push_back(i + 1);
	}
	p[a[0]] = 0;
	for (int i = 0; i < v.size() - 2; i++)
	{
		int l = v[i], m = v[i + 1], r = v[i + 2];
		//cout << l << m << r << endl;
		for (int i = m; i < r; i++) p[a[i]] = a[l];
	}
	puts("Yes");
	for (int i = 1; i <= n; i++)
	{
		printf("%d%c", p[i], " \n"[i == n]);
	}
}

int main()
{
	int _; scanf("%d", &_);
	while (_--) solve();
	return 0;
}
