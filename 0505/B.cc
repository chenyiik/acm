#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

const int maxn = int(1e5) + 10;
double a[maxn], b[maxn];

void read(double a[], int n, int t)
{
	priority_queue<double> PQ;
	for (int i = 0; i < n; i++)
	{
		int x; scanf("%d", &x);
		PQ.push(x);
	}
	for (int m = 0; m < t; m++)
	{
		double d = PQ.top();
		PQ.pop();
		a[m] = d;
		PQ.push(d * 0.6);
	}
}

int main()
{
	int n, m, t, k; scanf("%d%d%d%d", &n, &m, &t, &k);
	read(a, n, t), read(b, m, t);
	double tmp = 0;
	for (int i = 0; i < t; i++)
		tmp += a[i];
	double ans = tmp;
	for (int i = 0; i < t; i++)
	{
		if (i < t - k)
			tmp = tmp + b[i] - a[t - i - 1];
		else
			tmp = tmp + b[i] * 0.8 - a[t - i - 1];
		ans = max(ans, tmp);
	}
	printf("%.2f\n", ans);
	return 0;
}
