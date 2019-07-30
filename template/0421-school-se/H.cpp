#include<bits/stdc++.h>
#define M 1000005
#define LL unsigned long long
using namespace std;
void Rd(int &res){
	res=0;
	char c;
	while(c=getchar(),!isdigit(c));
	do{
		res=(res*10)+(c^48);
	}while(c=getchar(),isdigit(c));
}
int fa[M],cnt[M];
struct node{
	int a,b,c;
}A[M];
int get(int x){return fa[x]==x?x:fa[x]=get(fa[x]);}
bool cmp(node a,node b){
	return a.c<b.c;
}
int main(){
	int T;
	Rd(T);
	while(T--){
		int i,n;
		LL ans=0;
		Rd(n);
		for(i=1;i<n;i++){
			Rd(A[i].a),Rd(A[i].b),Rd(A[i].c);
			fa[i]=i;
			cnt[i]=1;
		}
		fa[n]=n;
		cnt[n]=1;
		sort(A+1,A+n,cmp);
		for(i=1;i<n;i++){
			int a=A[i].a;
			int b=A[i].b;
			int c=A[i].c;
			int x=get(a);
			int y=get(b);
			ans+=1LL*cnt[x]*cnt[y]*c;
			cnt[x]+=cnt[y];
			fa[y]=x;
		}
		cout<<ans<<endl;
	}
	return 0;
}
