#include<cstdio>
#define M 1000005
#define LL long long
int X[M];
int main(){
	int i,n,m,q;
	scanf("%d %d %d",&n,&m,&q);
	for(i=1;i<=n;i++)
		scanf("%d",&X[i]);
	while(q--){
		int p,k;
		scanf("%d %d",&p,&k);
		int sum=(1LL*X[k]*p)%(2LL*m);
		if(sum>=m)
			printf("%d\n",2*m-sum);
		else printf("%d\n",sum);
	}
	return 0;
}
