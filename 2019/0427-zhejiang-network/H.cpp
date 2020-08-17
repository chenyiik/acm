#include<cstdio>
#include<algorithm>
#define M 100005
#define MX 0x7fffffff
using namespace std;
int A[M],B[10],C[10];
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		int i,j,n,ans=0;
		scanf("%d",&n);
		for(i=3;i<=n+2;i++){
			scanf("%d",&A[i]);
		}
		A[1]=A[2]=A[n+3]=A[n+4]=MX;
		for(i=3;i<=n+2;i++){
			int p=0,p2=0;
			for(j=-2;j<=2;j++){
				B[p++]=A[i+j];
				if(j!=0)C[p2++]=A[i+j];
			}
			int tmp=0,tmp2=0;
			for(j=1;j<p-1;j++){
				if(B[j]>B[j-1]&&B[j]>B[j+1]){
					tmp++;
				}
			}
			for(j=1;j<p2-1;j++){
				if(C[j]>C[j-1]&&C[j]>C[j+1]){
					tmp2++;
				}
			}
			ans=min(ans,tmp2-tmp);
		}
		for(i=4;i<=n+1;i++){
			if(A[i]>A[i-1]&&A[i]>A[i+1])
				ans++;
		}
		printf("%d\n",ans);
	}
	return 0;
}
