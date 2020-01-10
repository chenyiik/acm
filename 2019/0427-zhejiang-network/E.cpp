#include<bits/stdc++.h>
using namespace std;
#define M 100005
int A[M];
int mark[M];
int main(){
	int T;
	scanf("%d",&T);
	for(int cas=1;cas<=T;cas++){
		int i,n;
		scanf("%d",&n);
		int ans=0;
		int ma=0,cma=0;
		bool flag=0;
		for(i=1;i<=n;i++){
			scanf("%d",&A[i]);
			if(i==1)ma=A[i];
			else{
				if(A[i]>=ma)
					ma=A[i];
				else{
					mark[i]=cas;
					if(!flag){
						cma=A[i];
						flag=1;
					}else{
						cma=max(cma,A[i]);
					}
				}
			}
		}
		for(i=1;i<=n;i++){
			if(flag&&A[i]<cma){
				mark[i]=cas;
			}
			if(mark[i]==cas){
				ans++;
			}
		}
		printf("%d\n",ans);
	}
}
