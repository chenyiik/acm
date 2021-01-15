#include<cstdio>
#define M 200005
int X[M],C[M];
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		int i,n,h,H;
		scanf("%d %d %d",&n,&h,&H);
		for(i=1;i<=n;i++){
			scanf("%d",&X[i]);
			int tmp=X[i]%(2*H);
			if(tmp>h&&tmp<2*H-h)
				X[i]+=2*H-h-tmp;
		}
		int ans=5*M,ply=-1;
		for(i=1;i<=n;i++){
			scanf("%d",&C[i]);
			X[i]+=C[i];
			if(X[i]<ans){
				ans=X[i];
				ply=i;
			}
		}
		printf("%d\n",ply);
	}
	return 0;
}
