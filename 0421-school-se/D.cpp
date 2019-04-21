#include<bits/stdc++.h>
#define M 100005
int A[M<<1];
int ans[M];
int gcd(int a,int b){return b==0?a:gcd(b,a%b);}
int main(){
	int T;
	scanf("%d",&T);
	for(int cas=1;cas<=T;cas++){
		memset(ans,0,sizeof(ans));
		int i,n,m;
		scanf("%d %d",&n,&m);
		for(i=1;i<=m;i++){
			int x;
			scanf("%d",&x);
			A[x]=A[x+n]=cas;
		}
		int his=-1;
		for(i=n<<1;i>0;i--){
			if(A[i]==cas)his=i;
			if(i<=n)
				ans[his-i+1]++;
		}
		for(i=1;i<=n;i++){
			if(ans[i]==0){
				puts("0");
			}else{
				int d=gcd(ans[i],n);
				printf("%d/%d\n",ans[i]/d,n/d);
			}
		}
	}
	return 0;
}
