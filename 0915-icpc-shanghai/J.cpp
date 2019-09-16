#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cctype>
#define M 505
#define SM 305
#define P 1000000007
using namespace std;
int A[SM],sum[SM];
int dp[2][M*SM*2];
int sum2[M*SM*2];
int sum3[M*SM*2];
void Rd(int &res){
	res=0;
	char c;
	while(c=getchar(),!isdigit(c));
	do{
		res=(res*10)+(c^48);
	}while(c=getchar(),isdigit(c));
}
int main(){
	int T;
	Rd(T);
	while(T--){
		int i,j,n;
		//build(1,base*2,1);
		Rd(n);
		int base=0;
		int ans=0;
		for(i=1;i<=n;i++){
			Rd(A[i]);
			base+=A[i];
		}
		base++;
		int L=base,R=base;
		memset(dp[1],0,base*2*sizeof(int));
		memset(dp[0],0,base*2*sizeof(int));
		dp[1][base]=1;
		memset(sum2,0,base*sizeof(int));
		memset(sum3,0,base*sizeof(int));
		for(i=base;i<=base*2;i++)
			sum3[i]=sum2[i]=1;
		sort(A+1,A+n+1);
		for(i=1;i<=n;i++)
			sum[i]=sum[i-1]+A[i];
		/*for(i=1;i<=n;i++)
			printf("%d ",A[i]);
		puts("");*/
		//puts("");
		int *dp0 = dp[0], *dp1 = dp[1];
		for(i=n;i>0;i--){
			int mns=sum[i-1];
			swap(dp0, dp1);
			ans=(ans+sum2[base+mns])%P;
			if(mns-A[i]-1>=0){
				ans=(ans+P-sum2[base+mns-A[i]-1])%P;
			}else{
				ans=(ans+P-sum2[base-1])%P;
				ans=(ans+(sum2[base-(mns-A[i])]+P-sum2[base])%P)%P;
			}
			memset(dp1 + L, 0, sizeof(int) * (R - L + 1));
			/*
			for(j=L;j<=R;j++){
				dp0[j]=dp1[j];
				dp1[j]=0;
			}
			*/
			int k=L;
			do{
				//printf("[%d,%d] ",k-base,dp0[k]);
				dp1[k+A[i]]=(dp1[k+A[i]]+dp0[k])%P;
				int tmp=k-A[i];
				if(k-A[i]<base)
					tmp=2*base-tmp;
				dp1[tmp]=(dp1[tmp]+dp0[k])%P;
				k=upper_bound(sum3+k,sum3+R+1,sum3[k])-sum3;
			}while(k<=R);
			//puts("");
			R+=A[i];
			for(j=L;j<=base*2;j++){
				sum2[j]=(sum2[j-1]+dp1[j])%P;
				sum3[j]=sum3[j-1]+(dp1[j]!=0);
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
