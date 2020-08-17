#include<cstdio>
#include<iostream>
#include<cstring>
#define M 100050
#define LL long long
using namespace std;
char str[M];
int dp[3][M];
int main(){
	memset(str,0,sizeof(str));
	int i,n,sum=0;
	LL ans=0;
	str[0]='0';
	scanf("%s",str+1);
	n=strlen(str+1);
	for(i=0;i<=n;i++){
		for(int j=0;j<3;j++)
			dp[j][i]=dp[j][i-1];
		sum=(sum+str[i]-'0')%3;
		dp[sum][i]++;
		if(str[i+1]=='0'&&str[i+2]=='0'){
			ans+=dp[sum][i];
		}
	}
	for(i=1;i<=n;i++)
		if(str[i]=='0')
			ans++;
	cout<<ans<<endl;
	return 0;
}
