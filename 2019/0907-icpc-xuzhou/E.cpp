#include<cstdio>
#include<cctype>
#include<iostream>
#include<algorithm>
#define M 500005
using namespace std;
void Rd(int &res){
	res=0;
	char c;
	while(c=getchar(),!isdigit(c));
	do{
		res=(res*10)+(c^48);
	}while(c=getchar(),isdigit(c));
}
int A[M<<1],B[M<<1],mx[M<<1];
struct node{
	int L,R,x;
}tree[M<<2];
void up(int p){
	tree[p].x=max(tree[p<<1].x,tree[p<<1|1].x);
}
void build(int L,int R,int p){
	tree[p].L=L;
	tree[p].R=R;
	if(L==R){
		tree[p].x=mx[L];
		return;
	}
	int mid=(L+R)>>1;
	build(L,mid,p<<1);
	build(mid+1,R,p<<1|1);
	up(p);
}
int query(int L,int R,int p){
	if(tree[p].L==L&&tree[p].R==R)
		return tree[p].x;
	int mid=(tree[p].L+tree[p].R)>>1;
	if(R<=mid)return query(L,R,p<<1);
	else if(L>mid)return query(L,R,p<<1|1);
	else return max(query(L,mid,p<<1),query(mid+1,R,p<<1|1));
}
int main(){
	int i,n,m;
	Rd(n),Rd(m);
	for(i=1;i<=n;i++){
		Rd(A[i]);
		A[i+n]=A[i]+m;
		B[i-1]=A[i];
		B[i+n-1]=A[i+n];
	}
	/*
	for(i=1;i<=n;i++)
		printf("%d\t",A[i]);
	puts("");
	for(i=1;i<=n;i++)
		printf("%d\t",A[i+n]);
	puts("");
	puts("");
	*/
	sort(B,B+2*n);
	int p=unique(B,B+2*n)-B;
	for(i=1;i<=2*n;i++){
		A[i]=lower_bound(B,B+p,A[i])-B+1;
		if(i<=n)mx[A[i]]=i;
	}
	/*
	for(i=1;i<=n;i++)
		printf("%d\t",A[i]);
	puts("");
	for(i=1;i<=n;i++)
		printf("%d\t",A[i+n]);
	puts("");
	 */
	build(1,p,1);
	for(i=n+1;i<=2*n;i++){
		int x=query(A[i],p,1);
		if(x>i-n)
			printf("%d%c",x-(i-n)-1," \n"[i==2*n]);
		else
			printf("-1%c"," \n"[i==2*n]);
	}
	return 0;
}
