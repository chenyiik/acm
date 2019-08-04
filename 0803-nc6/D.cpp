#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#define M 1005
using namespace std;
int V[M];
bool mark[M];
bool judge(int x,int n,int K){
	int tmp;
	for(int i=1;i<=n;i++)
		mark[i]=0;
	while(K--){
		tmp=x;
		for(int i=n;i>0;i--){
			if(!mark[i]&&tmp>=V[i]){
				tmp-=V[i];
				mark[i]=1;
			}
		}
	}
	for(int i=1;i<=n;i++)
		if(!mark[i])
			return 0;
	return 1;
}
int main(){
	int cas,T;
	memset(mark,0,sizeof(mark));
	scanf("%d",&T);
	for(cas=1;cas<=T;cas++){
		int n,K,L=0,R=0,res=-1;
		scanf("%d %d",&n,&K);
		for(int i=1;i<=n;i++){
			scanf("%d",&V[i]);
			R+=V[i];
		}
		sort(V+1,V+n+1);
		while(L<=R){
			int mid=(L+R)>>1;
			//printf("%d %d %d\n",L,R,judge(mid,n,K));
			if(judge(mid,n,K)){
				res=mid;
				R=mid-1;
			}else L=mid+1;
		}
		int tmp=0;
		for(int i=1;i<=100;i++){
			if(res-i<=0)break;
			if(judge(res-i,n,K))tmp=i;
		}
		printf("Case #%d: %d\n",cas,res-tmp);
	}
	return 0;
}
