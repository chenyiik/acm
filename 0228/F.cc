#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int maxn = int(4e5) + 10;
vector<int> G[maxn];
int a[maxn], tail[maxn] sum[maxn];

void range_add(int l,int r,ll x)
ll range_ask(int l,int r)

int main()
{
	int n; scanf("%d", &n);
	tail[1] = n;
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
		G[a[i]].push_back(i);
	}
	for (int i = 1; i <= n; i++)
	{
		if (G[i].size() < 2)
			continue;
		for (int j = 1; j < G[i]; j++)
		{

		}
		for (int j : G[i])
		{
			int head = range_ask(j, j);
			tail[j] = tail[head];
			tail[head] = j - 1;
			range_add(j, tail[j], j - head);
		}
		range_add(G[i][0], G[i][G[i].size() - 1], 1);
	}
	return 0;
}
using ll=long long;
ll sum1[maxn*2],sum2[maxn*2];
inline int lowbit(int x) {return x&(-x);}
void add(int p,ll x)
{
	for (int i=p;i<=maxn;i+=lowbit(i)) sum1[i]+=x,sum[i]+=x*p;
}
void range_add(int l,int r,ll x)
{
	add(l,x),add(r+1,-x);
}
ll ask(int p)
{
	ll res=0;
	for (int i=p;i;i-=lowbit(i)) res+=(p+1)*sum1[i]-sum2[i];
	return res;
}
ll range_ask(int l,int r)
{
	return ask(r)-ask(l-1);
}
