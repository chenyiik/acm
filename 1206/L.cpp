#include<cstdio>
#include<iostream>
#include<algorithm>
#define LL long long
#define M 100005
using namespace std;
int A[M];
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		int i,n,k;
		scanf("%d %d",&n,&k);
		for(i=0;i<n;i++)
			scanf("%d",&A[i]);
		sort(A,A+n);
		LL ans=0;
		for(i=0;i<n-k;i++)
			ans+=A[i];
		if(k>0)
			ans=max(ans,1LL*A[n-1]);
		cout<<ans<<endl;
	}
	return 0;
}
