#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

const int maxn = int(1e5) + 7;
int n, m, q;
struct P { int x, y, v; } a[maxn];
struct q {int x1,y1,x2,y2;} qq[maxn];
const int M = maxn*100;
int maxx,maxy,tot;
int T[maxn],lson[M],rson[M],c[M];
int L[maxn],R[maxn];
int build(int l,int r){
	int root=tot++;
	c[root]=0;
	if(l!=r){
		int mid=(l+r)>>1;
		lson[root]=build(l,mid);
		rson[root]=build(mid+1,r);
	}
	return root;
}
int update(int root,int pos,int val){
	int newroot=tot++,tmp=newroot;
	c[newroot]=c[root]+val;
	int l=1,r=maxy;
	while(l<r){
		int mid=(l+r)>>1;
		if(pos<=mid){
			lson[newroot]=tot++;rson[newroot]=rson[root];
			newroot=lson[newroot];root=lson[root];
			r=mid;
		}else{
			rson[newroot]=tot++;lson[newroot]=lson[root];
			newroot=rson[newroot];root=rson[root];
			l=mid+1;
		}
		c[newroot]=c[root]+val;
	}
	return tmp;
}
int query(int root,int l,int r,int tl,int tr){
	if(l==tl&&r==tr)
		return c[root];
	int mid=(tl+tr)>>1;
	if(r<=mid)return query(lson[root],l,r,tl,mid);
	if(l>mid)return query(rson[root],l,r,mid+1,tr);
	return query(lson[root],l,mid,tl,mid)+query(rson[root],mid+1,r,mid+1,tr);
}
struct ls
{
    map<int,int> raw;
    int cl=0;
    int insert(int val)
    {
		if (raw.count(val)) return raw[val];
        raw[val]=++cl;
        return cl;
    }
    int find_greater(int val)
    {
        return (raw.lower_bound(val))->second;
    }
    int find_less(int val)
    {
        return (--raw.upper_bound(val))->second;
    }
};
ls lsx,lsy;
int calc2(long long x)
{
	int ret = 0;
	while (x)
		ret += x % 10, x /= 10;
	return ret;
}
int calc(int x, int y)
{
	long long ans;
	long long r, area;
	if (x == y && x + y == n + 1)
	{
		ans = (long long)n * n;
		return calc2(ans);
	}
	if (x >= y && x + y > n + 1)
	{
		area = 0, r = n + 1 - x;
		ans = x - y + 1;
	}
	if (x > y && x + y <= n + 1)
	{
		area = 1, r = y;
		ans = n + 1 - y - x + 1;
	}
	if (x <= y && x + y < n + 1)
	{
		area = 2, r = x;
		ans = y - x + 1;
	}
	if (x < y && x + y >= n + 1)
	{
		area = 3, r = n + 1 - y;
		ans = x - (n + 1 - y) + 1;
	}
	r--;
	ans += 4 * (r * n - r * r);
	r++;
	ans += area * (n - 2 * r + 1);
	return calc2(ans);
}
void init()
{
	lsx.cl=lsy.cl=0;
	lsx.raw.clear();
	lsy.raw.clear();
	scanf("%d%d%d", &n, &m, &q);
	for (int i = 1; i <= m; i++)
	{
		scanf("%d%d", &a[i].x, &a[i].y);
		a[i].v = calc(a[i].x, a[i].y);
		//cout << a[i].v << endl;
		a[i].x=lsx.insert(a[i].x);
		a[i].y=lsy.insert(a[i].y);
	}
	for (int i=1;i<=q;i++)
    {
	    scanf("%d%d%d%d",&qq[i].x1,&qq[i].y1,&qq[i].x2,&qq[i].y2);
	    qq[i].x1=lsx.find_greater(qq[i].x1);
	    qq[i].y1=lsy.find_greater(qq[i].y1);
	    qq[i].x2=lsx.find_less(qq[i].x2);
	    qq[i].y2=lsy.find_less(qq[i].y2);
    }
}
bool cmp(P a,P b){
	return a.x<b.x;
}
int main()
{
	int _; scanf("%d", &_);
	while (_--)
	{
		init();
		int i;
		tot=0;
		maxx=lsx.cl;
		maxy=lsy.cl;
		T[0]=build(1,maxy);
		sort(a+1,a+1+m,cmp);
		for(i=1;i<=m;i++)
			T[i]=update(T[i-1],a[i].y,a[i].v);
		L[0]=R[0]=0;
		for(i=1;i<=maxx;i++){
			L[i]=R[i-1]+1;
			R[i]=L[i];
			while(a[R[i]].x==i&&R[i]<=m)R[i]++;
			R[i]--;
		}
		for(i=1;i<=q;i++){
			printf("%d\n",query(T[R[qq[i].x2]],qq[i].y1,qq[i].y2,1,maxy)-query(T[L[qq[i].x1]-1],qq[i].y1,qq[i].y2,1,maxy));
		}
	}
	return 0;
}
