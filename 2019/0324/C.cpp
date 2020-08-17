#include<bits/stdc++.h>
#define M 200005
#define LL long long
using namespace std;
void Rd(LL &res){
	res=0;
	char c;
	while(c=getchar(),!isdigit(c));
	do{
		res=(res*10)+(c^48);
	}while(c=getchar(),isdigit(c));
}
priority_queue<LL,vector<LL>,greater<LL> >Q;
map<int,int>mp;
int main(){
	int i,n;
	LL ans=0,x;
	scanf("%d",&n);
	x=1;
	mp[x]=0;
	for(i=1;i<=30;i++){
		x<<=1;
		mp[x]=mp[x>>1]+1;
	}
	for(i=1;i<=n;i++){
		Rd(x);
		Q.push(x);
	}
	while((int)Q.size()>1){
		LL a=Q.top();
		Q.pop();
		LL b=Q.top();
		Q.pop();
		if(b%a!=0){
			puts("-1");
			return 0;
		}
		ans+=mp[b/a];
		Q.push(b<<1);
	}
	cout<<ans<<endl;
	return 0;
}
