#include <cstdio>
#include <cctype>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <utility>

using namespace std;
void Rd(int &res){
	res=0;
	char c;
	while(c=getchar(),!isdigit(c));
	do{
		res=(res*10)+(c^48);
	}while(c=getchar(),isdigit(c));
}

const int maxn = int(1e6) + 5;
pair<int, int> a[maxn];
int d[maxn * 2], nxt[maxn * 2];

int dfs(int i) { return nxt[i] == i ? i : nxt[i] = dfs(nxt[i]); }

int main()
{
	int n, q;
	Rd(n), Rd(q);
	int m = q;
	for (int i = 0; i < q; i++)
	{
		Rd(a[i].first), Rd(a[i].second);
		d[i] = a[i].second;
		if (a[i].first == 1)
			d[m++] = a[i].second + 1;
	}
	d[m++] = 0;
	sort(d, d + m), m = unique(d, d + m) - d;
	for (int i = 0; i < m; i++)
		nxt[i] = i;
	for (int i = 0; i < q; i++)
	{
		if (a[i].first == 1)
		{
			int index = lower_bound(d, d + m, a[i].second) - d;
			if (nxt[index] == index)
				nxt[index] = index + 1;
		}
		else
		{
			int index = lower_bound(d, d + m, a[i].second) - d;
			printf("%d\n", d[dfs(index)]);
		}
	}
	return 0;
}
