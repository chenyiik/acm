#include<bits/stdc++.h>
#define M 500005
#define LL long long
using namespace std;
int A[M];
int main(){
	int i,n,buy=0,sell=-1;
	LL ans=0;
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%d",&A[i]);
		if(i==1){
			buy=A[i];
			continue;
		}
		if(A[i]<A[i-1]){
			if(sell>0){
				ans+=sell-buy;
				sell=0;
			}
			buy=A[i];
			continue;
		}
		if(A[i]>A[i-1])
			sell=A[i];
	}
	if(sell>0)
		ans+=sell-buy;
	cout<<ans<<endl;
	return 0;
}
