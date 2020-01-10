#include<bits/stdc++.h>
#define M 100005
#define SM 32
using namespace std;
struct node{
	int to,v;
};
struct node2{
	int id,a,b,c;
}edge2[M],Q[M];
struct node3{
	int L,R,sum;
}tree[M<<2];
int fa[M][SM],dep[M],cnt=0,L[M],R[M],ord[M],dly[M<<2],ans[M];
vector<node>edge[M];
void down(int p){
	dly[p<<1]+=dly[p];
	dly[p<<1|1]+=dly[p];
	tree[p<<1].sum+=dly[p];
	tree[p<<1|1].sum+=dly[p];
	dly[p]=0;
}
bool cmp(node2 a,node2 b){
	return a.c<b.c;
}
void dfs(int x,int f){
	fa[x][0]=f;
	dep[x]=dep[f]+1;
	for(int i=0;i<(int)edge[x].size();i++){
		int y=edge[x][i].to;
		if(y==f)continue;
		dfs(y,x);
	}
}
void dfs2(int x,int f){
	ord[++cnt]=x;
	L[x]=cnt;
	for(int i=0;i<(int)edge[x].size();i++){
		int y=edge[x][i].to;
		if(y==f)continue;
		dfs2(y,x);
	}
	R[x]=cnt;
}
int LCA(int a,int b){
	if(dep[b]<dep[a])swap(a,b);
	int jp;
	for(jp=SM-1;jp>=0;jp--)
		if(dep[fa[b][jp]]>=dep[a])
			b=fa[b][jp];
	if(b==a)return a;
	for(jp=SM-1;jp>=0;jp--)
		if(fa[b][jp]!=fa[a][jp]){
			a=fa[a][jp];
			b=fa[b][jp];
		}
	return fa[a][0];
}
void build(int L,int R,int p){
	tree[p].L=L;
	tree[p].R=R;
	tree[p].sum=0;
	if(L==R)return;
	int mid=(L+R)>>1;
	build(L,mid,p<<1);
	build(mid+1,R,p<<1|1);
}
int query(int x,int p){
	if(tree[p].L==tree[p].R)return tree[p].sum;
	down(p);
	int mid=(tree[p].L+tree[p].R)>>1;
	if(x<=mid)return query(x,p<<1);
	return query(x,p<<1|1);
}
void update(int L,int R,int p){
	//printf("%d %d %d %d\n",L,R,tree[p].L,tree[p].R);
	if(tree[p].L==L&&tree[p].R==R){
		tree[p].sum++;
		dly[p]++;
		return;
	}
	int mid=(tree[p].L+tree[p].R)>>1;
	if(R<=mid)update(L,R,p<<1);
	else if(L>mid)update(L,R,p<<1|1);
	else{
		update(L,mid,p<<1);
		update(mid+1,R,p<<1|1);
	}
}
int main(){
	int i,j,n,m,a,b,c;
	scanf("%d %d",&n,&m);
	for(i=1;i<n;i++){
		scanf("%d %d %d",&a,&b,&c);
		edge[a].push_back((node){b,c});
		edge[b].push_back((node){a,c});
		edge2[i-1].a=a;
		edge2[i-1].b=b;
		edge2[i-1].c=c;
	}
	edge2[n-1].c=1000000007;
	for(i=0;i<m;i++){
		Q[i].id=i;
		scanf("%d %d %d",&a,&b,&c);
		Q[i].a=a;
		Q[i].b=b;
		Q[i].c=c;
	}
	sort(edge2,edge2+n-1,cmp);
	sort(Q,Q+m,cmp);
	dep[0]=0;
	dfs(1,0);
	for(j=1;j<SM;j++)
		for(i=1;i<=n;i++)
			fa[i][j]=fa[fa[i][j-1]][j-1];
	dfs2(1,0);
	build(1,n,1);
	i=0;
	for(j=0;j<m;j++){
		while(edge2[i].c<=Q[j].c){
			//printf("%d\n",i);
			a=edge2[i].a;
			b=edge2[i].b;
			c=edge2[i].c;
			if(fa[a][0]==b)update(L[a],R[a],1);
			else update(L[b],R[b],1);
			i++;
		}
		a=Q[j].a;
		b=Q[j].b;
		c=Q[j].c;
		int anc=LCA(a,b);
		//printf("%d %d %d\n",a,b,anc);
		ans[Q[j].id]=query(L[a],1);
	//	puts("a");
		ans[Q[j].id]+=query(L[b],1);
		//puts("b");
		ans[Q[j].id]-=2*query(L[anc],1);
		//puts("c");
	}
	for(i=0;i<m;i++)
		printf("%d\n",ans[i]);
	return 0;
}
