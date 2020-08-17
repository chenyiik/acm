#include<bits/stdc++.h>
#define M 200005
using namespace std;
struct node{
	int a,b;
	bool operator<(const node &x)const{
		return b>x.b;
	}
};
priority_queue<node>Q;
void Rd(int &res){
	res=0;
	char c;
	while(c=getchar(),!isdigit(c));
	do{
		res=(res*10)+(c^48);
	}while(c=getchar(),isdigit(c));
}
struct node2{
	int id,x,gp;
}A[M];
bool cmp(node2 a,node2 b){
	return a.x<b.x;
}
bool cmp2(node2 a,node2 b){
	return a.id<b.id;
}
int main(){
	int i,n,m,d,gp,maxgp=1;
	scanf("%d %d %d",&n,&m,&d);
	gp=min(n,d+1);
	for(i=1;i<=n;i++){
		A[i].id=i;
		Rd(A[i].x);
	}
	sort(A+1,A+1+n,cmp);
	for(i=1;i<=n;i++){
		if(Q.empty()){
			Q.push((node){1,A[i].x});
			A[i].gp=1;
			continue;
		}
		node now=Q.top();
		if(A[i].x-now.b<=d){
			maxgp++;
			A[i].gp=maxgp;
			Q.push((node){maxgp,A[i].x});
			continue;
		}
		Q.pop();
		A[i].gp=now.a;
		Q.push((node){A[i].gp,A[i].x});
	}
	printf("%d\n",maxgp);
	sort(A+1,A+1+n,cmp2);
	for(i=1;i<=n;i++)
		printf("%d%c",A[i].gp," \n"[i==n]);
	return 0;
}
