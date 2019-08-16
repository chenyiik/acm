#include<cstdio>
#include<iostream>
#include<algorithm>
#define LL long long
#define P 1000000007
using namespace std;
LL quick(LL x,int a){
	LL res=1;
	while(a>0){
		if(a&1)res=res*x%P;
		a>>=1;
		x=x*x%P;
	}
	return res;
}
void solve(){
	LL b,c;
	int s=((P-1)/2+1)/2;
	cin>>b>>c;
	LL delta=(b*b%P-4*c%P+P)%P;
	LL euler=quick(delta,(P-1)/2);
	if(euler==P-1){
		puts("-1 -1");
		return;
	}
	LL sd=quick(delta,s);
	LL x=((b-sd+P)*quick(2,P-2))%P;
	LL y=(b+P-x)%P;
	if(x>y)swap(x,y);
	cout<<x<<" "<<y<<endl;
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--)solve();
	return 0;
}
