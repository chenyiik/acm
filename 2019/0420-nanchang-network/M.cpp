#include<bits/stdc++.h>
#define M 100005
#define SM 1005
char S[M];
char T[SM];
int dp[M][128];
int main(){
	scanf("%s",S+1);
	int n=strlen(S+1);
	int i,j;
	for(j=0;j<128;j++){
		int his=-1;
		for(i=n;i>=0;i--){
			dp[i][j]=his;
			if(S[i]==j)
				his=i;
		}
	}
	int N;
	scanf("%d",&N);
	while(N--){
		scanf("%s",T);
		int p=0;
		bool flag=1;
		int len=strlen(T);
		for(i=0;i<len;i++){
			if(dp[p][T[i]]!=-1)p=dp[p][T[i]];
			else{
				flag=0;
				break;
			}
		}
		if(flag)puts("YES");
		else puts("NO");
	}
	return 0;
}
