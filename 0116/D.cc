#include <cstdio>
#include <iostream>
#include <algorithm>
#include <utility>
#include <stack>

using namespace std;

const int maxn = int(1e5) + 5;
struct P { int id, value; } a[maxn], q[maxn];
int an = 0;

const int M = maxn * 4;
struct node{ int L,R,x,pos; }tree[M];
void up(int p);
void build(int L,int R,int p);
void update(int x,int a,int p);
pair<int,int> query(int L,int R,int p);

int main()
{
	int n, k; scanf("%d%d", &n, &k);
	build(1, n, 1);
	for (int i = 1; i <= n; i++)
	{
		int m, x; scanf("%d", &m);
		while (m--) scanf("%d", &x), a[++an] = {i, x};
	}
	if (an == 0) return puts("0"), 0;
	sort(a + 1, a + 1  + an, [](P a, P b) { return a.value < b.value; });
	int pos = 0;
	stack<pair<int, int>> St;
	for (int i = 1; i <= an; i++)
	{
		if (a[i].value > a[i - 1].value)
			while (!St.empty()) update(St.top().first, St.top().second, 1), St.pop();
		int r = a[i].id == 1 ? n : a[i].id - 1, l = r - k;
		//pair<int, int> ans = l > 0 ? query(l, r, 1) : max(query(1, r, 1), query(l + n, n, 1));
		pair<int, int> ans;
		if (l > 0) ans = query(l, r, 1);
		else
		{
			pair<int, int> p1 = query(1, r, 1), p2 = query(l + n, n, 1);
			ans = p1.first >= p2.first ? p1 : p2;
		}
		St.push(make_pair(a[i].id, ans.first + 1));
		q[i] = { ans.second, ans.first + 1 };
		if (q[i].value > q[pos].value) pos = i;
	}
	stack<P> S;
	S.push(a[pos]);
	for (int i = pos - 1; i > 0; i--)
		if (a[i].id == q[pos].id && q[i].value == q[pos].value - 1)
			S.push(a[pos = i]);
	printf("%lu\n", S.size());
	while (!S.empty()) printf("%d %d\n", S.top().id, S.top().value), S.pop();
	//for (int i = 1; i <= an; i++) cout << a[i].value << '\t' << a[i].id << '\t' << q[i].value << '\t' << q[i].id << endl;
	return 0;
}

void up(int p){
    if(tree[p<<1].x>=tree[p<<1|1].x){
        tree[p].x=tree[p<<1].x;
        tree[p].pos=tree[p<<1].pos;
    }else{
        tree[p].x=tree[p<<1|1].x;
        tree[p].pos=tree[p<<1|1].pos;
    }
}
void build(int L,int R,int p){
    tree[p].L=L;
    tree[p].R=R;
    tree[p].pos=L;
    tree[p].x=0;
    if(L==R)return;
    int mid=(L+R)>>1;
    build(L,mid,p<<1);
    build(mid+1,R,p<<1|1);
    up(p);
}
void update(int x,int a,int p){
    if(tree[p].L==tree[p].R){
        tree[p].x=a;
        return;
    }
    int mid=(tree[p].L+tree[p].R)>>1;
    if(x<=mid)update(x,a,p<<1);
    else update(x,a,p<<1|1);
    up(p);
}
pair<int,int> query(int L,int R,int p){
    if(tree[p].L==L&&tree[p].R==R)
        return make_pair(tree[p].x,tree[p].pos);
    int mid=(tree[p].L+tree[p].R)>>1;
    if(R<=mid)return query(L,R,p<<1);
    else if(L>mid)return query(L,R,p<<1|1);
    else //return max(query(L, mid, p << 1), query(mid + 1, R, p << 1 | 1));
	{
        pair<int,int> res=query(L,mid,p<<1);
        pair<int,int> res2=query(mid+1,R,p<<1|1);
        if(res.first>=res2.first)return res;
        return res2;
    }
}
