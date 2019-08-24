#include<cstdio>
#include<cstring>
#include<algorithm>
#define LL long long
#define M 100005
using namespace std;
int a[M];
struct node{
	int L,R,mx;
}tree[M<<2];
void build(int L,int R,int p){
	tree[p].L=L;
	tree[p].R=R;
	tree[p].mx=0;
	if(L==R) return;
	int mid=(L+R)>>1;
	build(L,mid,p<<1);
	build(mid+1,R,p<<1|1);
}
void up(int p){
	tree[p].mx=max(tree[p<<1].mx,tree[p<<1|1].mx);
}
void update(int x,int a,int p){
	if(tree[p].L==tree[p].R){
		tree[p].mx=a;
		return;
	}
	int mid=(tree[p].L+tree[p].R)>>1;
	if(x<=mid)update(x,a,p<<1);
	else update(x,a,p<<1|1);
	up(p);
}
int query(int r,int k,int p){
	//printf("%d %d %d %d\n",r,k,tree[p].L,tree[p].R);
	if(tree[p].L==tree[p].R){
		if(tree[p].L<k||tree[p].mx<=r)return -1;
		return tree[p].L;
	}
	int mid=(tree[p].L+tree[p].R)>>1;
	if(k>mid||tree[p<<1].mx<=r)return query(r,k,p<<1|1);
	if(tree[p].L>=k){
		if(tree[p<<1].mx>r)return query(r,k,p<<1);
		return query(r,k,p<<1|1);
	}
	int ans=query(r,k,p<<1);
	if(ans<0)return query(r,k,p<<1|1);
	return ans;
}
void solve(int n,int m){
	int i,ans=0;
	build(1,n+1,1);
	for(i=1;i<=n;i++)
		update(a[i],i,1);
	update(n+1,n+1,1);
	while(m--){
		int op;
		scanf("%d",&op);
		if(op==1){
			LL t1;
			scanf("%lld",&t1);
			int pos=t1^ans;
			update(a[pos],n+1,1);
		}else{
			LL t2,t3;
			int r,k;
			scanf("%lld %lld",&t2,&t3);
			r=t2^ans;
			k=t3^ans;
			ans=query(r,k,1);
			printf("%d\n",ans);
		}
	}
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		int i,n,m;
		scanf("%d %d",&n,&m);
		for(i=1;i<=n;i++)
			scanf("%d",&a[i]);
		solve(n,m);
	}
	return 0;
}
