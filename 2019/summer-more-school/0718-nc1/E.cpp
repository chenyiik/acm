#include<cstdio>
#include<cstring>
#define M 1005
#define P 1000000007
int dp[M*4][M*2];
int main(){
	int n,m;
	while(scanf("%d %d",&n,&m)!=EOF){
		int i,j;
		dp[0][M]=1;
		for(i=1;i<=2*(n+m);i++){
			dp[i][M-m]=dp[i-1][M-m+1];
			dp[i][M+n]=dp[i-1][M+n-1];
			for(j=M-m+1;j<=M+n-1;j++)
				dp[i][j]=(dp[i-1][j-1]+dp[i-1][j+1])%P;
		}
		printf("%d\n",dp[2*(n+m)][M]);
	}
	return 0;
}
