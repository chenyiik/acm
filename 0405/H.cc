#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

const int maxn = int(1e5) + 10;
int t[maxn], r[maxn];
struct P
{
	int a, b, c;
	bool operator<(const P &o) const { return a < o.a; }
} s[maxn];

struct R
{
	int right, id;
	bool operator<(R o) const { return right > o.right; }
};

bool init(int n, int k);
void solve(int n, int k);
void out(int n);

int main()
{
	int n, k; scanf("%d%d", &n, &k);
	if (!init(n, k))
		return puts("Impossible"), 0;
	solve(n, k);
	out(n);
	return 0;
}

void build(int L,int R,int p);
void update(int L,int R,int x,int p);
int query(int L,int R,int p);

void solve(int n, int k)
{
	build(1, max(1, k), 1);
	for (int i = 1; i <= k; i++)
		update(i, i, s[i].c, 1);
	priority_queue<R> Q;
	int cnt = 1;
	for (int i = 1; i <= n; i++)
	{
		while (cnt <= k && s[cnt].a == i)
			Q.push({s[cnt].b, cnt}), cnt++;
		if (t[i] == 0)
		{
			if (Q.empty())
				r[i] = -1;
			else if (query(1, cnt - 1, 1) >= 2)
			{
				r[i] = -1;
				update(1, cnt - 1, -2, 1);
			}
			else
				r[i] = 1;
		}
		else
			r[i] = t[i];
		while (!Q.empty() && Q.top().right == i)
		{
			int u = Q.top().id; Q.pop();
			update(u, u, int(1e9), 1);
		}
	}
}

int sum(int x);
void add(int x, int d, int n);

bool init(int n, int k)
{
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &t[i]);
		if (t[i] == -1)
			add(i, -1, n);
		else
			add(i, 1, n);
	}
	for (int i = 1; i <= k; i++)
	{
		scanf("%d%d%d", &s[i].a, &s[i].b, &s[i].c);
		s[i].c = sum(s[i].b) - sum(s[i].a - 1) - s[i].c;
		if (s[i].c < 0)
			return false;
	}
	sort(s + 1, s + 1 + k);
	return true;
}

void out(int n)
{
	for (int i = 1; i <= n; i++)
		printf("%d%c", r[i], " \n"[i == n]);
}

int C[maxn * 2]; //from 1 to n

int lowbit(int x) { return x & -x; }

int sum(int x)
{
	int ret = 0;
	while (x > 0)
	{
		ret += C[x];
		x -= lowbit(x);
	}
	return ret;
}

void add(int x, int d, int n)
{
	while (x <= n)
	{
		C[x] += d;
		x += lowbit(x);
	}
}

struct node{
    int L,R,x;
}tree[maxn<<2];
int lzy[maxn<<2];
void build(int L,int R,int p){
    tree[p].L=L;
    tree[p].R=R;
    tree[p].x=0;
    lzy[p]=0;
    if(L==R)return;
    int mid=(L+R)>>1;
    build(L,mid,p<<1);
    build(mid+1,R,p<<1|1);
}
void up(int p){
    tree[p].x=min(tree[p<<1].x,tree[p<<1|1].x);
}
void down(int p){
    lzy[p<<1]+=lzy[p];
    lzy[p<<1|1]+=lzy[p];
    tree[p<<1].x+=lzy[p];
    tree[p<<1|1].x+=lzy[p];
    lzy[p]=0;
}
void update(int L,int R,int x,int p){
    if(tree[p].L==L&&tree[p].R==R){
        tree[p].x+=x;
        lzy[p]+=x;
        return;
    }
    down(p);
    int mid=(tree[p].L+tree[p].R)>>1;
    if(R<=mid)update(L,R,x,p<<1);
    else if(L>mid)update(L,R,x,p<<1|1);
    else{
        update(L,mid,x,p<<1);
        update(mid+1,R,x,p<<1|1);
    }
    up(p);
}
int query(int L,int R,int p){
    if(tree[p].L==L&&tree[p].R==R)
        return tree[p].x;
    down(p);
    int mid=(tree[p].L+tree[p].R)>>1;
    if(R<=mid)return query(L,R,p<<1);
    else if(L>mid)return query(L,R,p<<1|1);
    else return min(query(L,mid,p<<1),query(mid+1,R,p<<1|1));
}
