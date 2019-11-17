#include<cstdio>
#include<iostream>
#include<algorithm>
#define LL long long
#define M 4096
using namespace std;
LL gcd(LL a,LL b){return b?gcd(b,a%b):a;}
LL f(LL n,int m){
	int cnt=0;
	for(int i=1;i<M;i++){
		if(gcd(i+n,n)==1)cnt++;
		if(cnt==m)
			return i+n;
	}
	return n;
}
LL ans[M];
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		LL k;
		int m;
		cin>>k>>m;
		int p=0;
		for(int i=1;i<M;i++){
			LL n=k^i;
			if(((f(n,m)-n)^n)==k)
				ans[p++]=n;
		}
		if(p==0)puts("-1");
		else{
			sort(ans,ans+p);
			cout<<ans[0]<<endl;
		}
	}
	return 0;
}
