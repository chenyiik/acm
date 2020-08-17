#include<cstdio>
#include<algorithm>
#define M 1000005
#define P 21 
using namespace std;
char S[M],T[M];
char fa[M][P];
int pos(int n,int t,char x){
	if(S[t]>=x)return t;
	for(int jp=P-1;jp>=0;jp--){
		if(fa[t][jp]<x)
			t+=1<<jp;
		if(t>n)return -M;
	}
	return t+1;
}
int pos2(int n,int t,char x){
	if(S[t]==x)return t;
	for(int jp=P-1;jp>=0;jp--){
		if(fa[t][jp]<x)
			t+=1<<jp;
		if(t>n)return -M;
	}
	if(S[t+1]!=x)return -M;
	return t+1;
}
int dfs(int ps,int t,int n,int m){
	//printf("%d %d\n",ps,t);
	if(t>m)return max(0,n-ps+1);
	if(ps<=0)return -M;
	int BG=pos(n,ps,T[t]+1);
	int ans=BG>0?n-BG+1:-M;
	//printf("%d\n",ans);
	int EQ=pos2(n,ps,T[t]);
	//printf("EQ: %d\n",EQ);
	return max(ans,EQ>0?1+dfs(EQ+1,t+1,n,m):-M);
}
int main(){
	int i,j,n,m;
	scanf("%d %d %s %s",&n,&m,S+1,T+1);
	for(i=1;i<=n;i++)
		fa[i][0]=max(S[i],S[i+1]);
	for(j=1;j<P;j++)
		for(i=1;i<=n;i++)
			fa[i][j]=max(fa[i][j-1],fa[i+(1<<(j-1))][j-1]);
	printf("%d\n",max(-1,dfs(1,1,n,m)));
	return 0;
}
