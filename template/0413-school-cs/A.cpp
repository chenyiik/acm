#include<bits/stdc++.h>
#define LL long long
#define M 5005
using namespace std;
LL dfs(LL L,LL R){
	if(L<=1)L=2;
	if(L>R)
		return 0;
	LL ans=0;
	if(L<=9){
		ans+=min(R+1,10LL)-L;
	}
	for(int i=2;i<=9;i++){
		LL Lx,Rx;
		Lx=L/i+(L%i!=0);
		Rx=R/i;
		ans+=dfs(Lx,Rx);
	}
	return ans;
}
int main(){
	int i,n;
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		LL L,R;
		scanf("%lld %lld",&L,&R);
		cout<<dfs(L,R)%1000000007<<endl;
	}
	return 0;
}
