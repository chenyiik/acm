#include<cstdio>
#include<cstring>
#include<algorithm>
#define LL long long
#define M 10005
using namespace std;
LL dp[M*2];
int main(){
	int n,m;
	while(scanf("%d %d",&n,&m)!=EOF){
		memset(dp,0x3f,sizeof(dp));
		LL a=(LL)1e17,b=0;
		dp[0]=0;
		int i,j;
		for(i=1;i<=n;i++){
			int p,c;
			scanf("%d %d",&p,&c);
			for(j=0;j<m;j++)
				if(dp[j]>=0)
					dp[j+c]=min(dp[j+c],dp[j]+p);
		}
		for(i=m;i<2*M;i++){
			if(dp[i]<a){
				a=dp[i];
				b=i;
			}
			if(dp[i]==a)
				b=i;
		}
		printf("%lld %lld\n",a,b);
	}
	return 0;
}
