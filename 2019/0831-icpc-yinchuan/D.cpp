#include<cstdio>
double dp[100];
double solve(int n){
	return n==1?1:0.5;
}
double solve2(int n){
	return ((n-1.0)/2.0+1.0)/n;
}
int main(){
	int T;
	scanf("%d",&T);
	for(int cas=1;cas<=T;cas++){
		int n,m;
		scanf("%d %d",&n,&m);
		printf("Case #%d: %.6f %.6f\n",cas,solve(n),solve2(m));
	}
	return 0;
}
