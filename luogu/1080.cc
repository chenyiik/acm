#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int base = (int)1e4;

void mul(vector<long long> &v, int c)
{
	int x = 0;
	for (long long &i : v)
	{
		i = i * c + x;
		x = i / base;
		i %= base;
	}
	if (x)
		v.push_back(x);
}

void div(vector<long long> &v, int d)
{
	for (int i = v.size() - 1; i > 0; i--)
	{
		v[i - 1] += v[i] % d * base;
		v[i] /= d;
	}
	v[0] /= d;
	while (v.size() > 1 && v[v.size() - 1] == 0)
		v.pop_back();
}

struct P { int a, b; } arr[1005];

void maxv(vector<long long> &a, const vector<long long> &b)
{
	if (b.size() < a.size()) 
		return;
	if (b.size() == a.size())
	{
		for (int i = a.size() - 1; i >= 0; i--)
		{
			if (i == 0 && b[i] == a[i])
				return;
			else if (b[i] > a[i])
				break;
			else if (b[i] < a[i])
				return;
		}
	}
	a = b;
}

int main()
{
	int n = 0;
	scanf("%d", &n);
	vector<long long> v(1);
	scanf("%lld%*d", &v[0]);
	for (int i = 0; i < n; i++)
		scanf("%d%d", &arr[i].a, &arr[i].b);
	sort(arr, arr + n, [](P x, P y) { return x.a * x.b < y.a * y.b; });
	vector<long long> ans(1);
	for (int i = 0; i < n; i++)
	{
		vector<long long> u(v);
		div(u, arr[i].b);
		maxv(ans, u);
		mul(v, arr[i].a);
	}
	printf("%lld", ans[ans.size() - 1]);
	for (int i = ans.size() - 2; i >= 0; i--)
		printf("%04lld", ans[i]);
	puts("");
	return 0;
}
