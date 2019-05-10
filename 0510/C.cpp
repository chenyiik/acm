#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#define M 1005
#define P 998244353
using namespace std;
int A[M],B[M],cnt[M],dp[M][M];
int dfs(int n,int t,int rm){
	if(dp[t][rm]>=0)return dp[t][rm];
	if(rm==0)return dp[t][rm]=1;
	if(t>n)return 0;
	return dp[t][rm]=(1LL*cnt[t]*dfs(n,t+1,rm-1)%P+dfs(n,t+1,rm)%P)%P;
}
int main(){
	int i,n,k;
	memset(dp,-1,sizeof(dp));
	scanf("%d %d",&n,&k);
	for(i=1;i<=n;i++){
		scanf("%d",&A[i]);
		B[i-1]=A[i];
	}
	sort(B,B+n);
	int m=unique(B,B+n)-B;
	for(i=1;i<=n;i++)
		cnt[lower_bound(B,B+m,A[i])-B+1]++;
	printf("%d\n",dfs(n,1,k));
	return 0;
}
