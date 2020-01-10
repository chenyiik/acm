#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>
#define M 1000005
#define LL long long
using namespace std;
struct node{
	int L,R,cnt;
	LL sum;
}tree[M<<2];
vector<node>Q[M];
void up(int p){
	tree[p].cnt=tree[p<<1].cnt+tree[p<<1|1].cnt;
	tree[p].sum=tree[p<<1].sum+tree[p<<1|1].sum;
}
void build(int L,int R,int p){
	tree[p].L=L;
	tree[p].R=R;
	tree[p].cnt=0;
	tree[p].sum=0;
	if(L==R)return;
	int mid=(L+R)>>1;
	build(L,mid,p<<1);
	build(mid+1,R,p<<1|1);
}
void update(int x,int a,int p){
	if(tree[p].L==tree[p].R){
		tree[p].cnt+=a;
		tree[p].sum+=1LL*x*a;
		return;
	}
	int mid=(tree[p].L+tree[p].R)>>1;
	if(x<=mid)update(x,a,p<<1);
	else update(x,a,p<<1|1);
	up(p);
}
LL query(int k,int p){
	//printf("%d: [%d,%d]: %d\n",k,tree[p].L,tree[p].R,tree[p].cnt);
	if(tree[p].cnt<=k)
		return tree[p].sum;
	if(tree[p].L==tree[p].R)
		return 1LL*k*tree[p].L;
	if(tree[p<<1].cnt>=k)
		return query(k,p<<1);
	return tree[p<<1].sum+query(k-tree[p<<1].cnt,p<<1|1);
}
int main(){
	int i,n,k,m,l,r,c,p,mp=0;
	LL ans=0;
	scanf("%d %d %d",&n,&k,&m);
	for(i=1;i<=m;i++){
		scanf("%d %d %d %d",&l,&r,&c,&p);
		Q[l].push_back((node){l,l,c,p});
		Q[r+1].push_back((node){r,r,-c,p});
		mp=max(mp,p);
	}
	build(1,mp,1);
	for(i=1;i<=n;i++){
		for(int j=0;j<(int)Q[i].size();j++)
			update(Q[i][j].sum,Q[i][j].cnt,1);
		ans+=query(k,1);
		//printf("%I64d\n",ans);
	}
	cout<<ans<<endl;
	return 0;
}
