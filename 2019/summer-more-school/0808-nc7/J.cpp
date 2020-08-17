#include<cstdio>
#include<iostream>
#define LL long long
using namespace std;
LL f(LL x){
	LL tmp=0;
	while(x>0){
		tmp=tmp*10+x%10;
		x/=10;
	}
	return tmp;
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		LL a,b;
		cin>>a>>b;
		cout<<f(f(a)+f(b))<<endl;
	}
	return 0;
}
