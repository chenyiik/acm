#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <string>
#include <map>

using namespace std;

const int maxn = int(1e5) + 10;
char s[maxn];
int a[maxn], t[maxn];
long long sum;

void fuck(int l, int r)
{
	if (l + 1 == r) return;
	int mid = (l + r) / 2;
	fuck(l, mid), fuck(mid, r);
	for (int it = l, il = l, ir = mid; it < r; it++)
	{
		if (il == mid) t[it] = a[ir++];
		else if (ir == r || a[il] < a[ir]) t[it] = a[il++];
		else t[it] = a[ir++], sum += mid - il;
	}
	memcpy(a + l, t + l, sizeof(int) * (r - l));
}

int main()
{
	for (int n; ~scanf("%d", &n) && n; )
	{
		map<string, int> M;
		for (int i = 0; i < n; i++)
			scanf("%s", s), M[string(s)] = i;
		for (int i = 0; i < n; i++)
			scanf("%s", s), a[i] = M[string(s)];
		sum = 0;
		fuck(0, n);
		printf("%lld\n", sum);
	}
	return 0;
}
