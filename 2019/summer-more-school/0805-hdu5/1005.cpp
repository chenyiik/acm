#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#define M 25
using namespace std;
int F[M],A[M];
bool mark[M];
struct node{
	unsigned a,b;
};
void solve(int n,int k){
	memset(mark,0,sizeof(mark));
	int i;
	A[1]=n;
	for(i=2;i<=n;i++)
		A[i]=i-1;
	k--;
	if(k==0){
		for(i=1;i<=n;i++)
			printf("%d%c",A[i]," \n"[i==n]);
		return;
	}
	int x=1;
	while(F[x]<=k)x++;
	int base=n-x;
	for(int i=base+1;i<=n;i++){
		int p=base;
		while(mark[p])p++;
		while(k>=F[n-i]){
			do{
				p++;
			}while(mark[p]);
			k-=F[n-i];
		}
		mark[p]=1;
		A[i]=p;
	}
	for(i=1;i<=n;i++)
		printf("%d%c",A[i]," \n"[i==n]);
}
bool cmp(node a,node b){
	return a.a<b.a;
}
void solve2(int n,int k){
	int i;
	for(i=1;i<=n;i++)
		A[i]=i;
	vector<node>Q;
	do{
		node tmp;
		tmp.b=tmp.a=0;
		for(i=1;i<=n;i++)
			tmp.b=tmp.b*10+A[n-i+1];
		for(i=2;i<=n;i++)
			tmp.a=(tmp.a<<4)+(A[i]-A[i-1]+8);
		Q.push_back(tmp);
	}while(next_permutation(A+1,A+1+n));
	sort(Q.begin(),Q.end(),cmp);
	node ans=Q[k-1];
	i=0;
	while(ans.b>0){
		i++;
		A[i]=ans.b%10;
		ans.b/=10;
	}
	for(i=1;i<=n;i++)
		printf("%d%c",A[i]," \n"[i==n]);
}
int main(){
	int T;
	F[0]=1;
	for(int i=1;i<M;i++)
		F[i]=F[i-1]*i;
	scanf("%d",&T);
	while(T--){
		int n,k;
		scanf("%d %d",&n,&k);
		if(n>8)solve(n,k);
		else solve2(n,k);
	}
	return 0;
}
