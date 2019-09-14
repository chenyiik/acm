#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<vector>
#define M 100005
using namespace std;
vector<int>edge[M],edge2;
bool mo[M];
int fa[M],cnt[M];
int get(int x){return fa[x]==x?x:fa[x]=get(fa[x]);}
int dfs(int x,int f){
	int ans=cnt[x];
	fa[x]=1;
	for(int i=0;i<(int)edge[x].size();i++){
		int y=edge[x][i];
		if(y==f)continue;
		if(mo[y])
			edge2.push_back(y);
		else ans+=dfs(y,x);
	}
	return ans;
}
bool mark[M];
int dfs2(int x,int f){
	int ans=0;
	bool flag=0;
	mark[x]=1;
	for(int i=0;i<(int)edge[x].size();i++){
		int y=edge[x][i];
		if(y==f)continue;
		int fy=get(y);
		if(fy==1)continue;
		if(mark[fy]){
			flag=1;
			ans+=cnt[fy];
		}
		if(mo[y])continue;
		fa[y]=fy;
		ans+=dfs(y,x);
	}
	if(!flag&&fa[x]!=x)
		cnt[get(x)]++;
	return ans;
}
void solve(){
	int i,n,m,k;
	double ans=0;
	scanf("%d %d %d",&n,&m,&k);
	edge2.clear();
	for(i=1;i<=n;i++){
		mark[i]=0;
		edge[i].clear();
		fa[i]=i;
		cnt[i]=1;
		mo[i]=0;
	}
	for(i=1;i<=m;i++){
		int a,b;
		scanf("%d %d",&a,&b);
		edge[a].push_back(b);
		edge[b].push_back(a);
	}
	for(i=1;i<=k;i++){
		int x;
		scanf("%d",&x);
		mo[x]=1;
		cnt[x]=0;
	}
	cnt[1]=dfs(1,0);
	for(i=0;i<(int)edge2.size();i++){
		int y=edge2[i];
		printf("\t%d\n",dfs2(y,0));
		ans=max(ans,1.0*dfs2(y,0)/((int)edge[y].size()));
	}
	for(i=1;i<=n;i++)
		printf("%d ",cnt[i]);
	puts("");
	printf("%.6lf\n",ans+cnt[1]);
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--)solve();
	return 0;
}
