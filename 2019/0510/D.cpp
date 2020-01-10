#include<cstdio>
#define P 1000000009
int A[1005];
int quick(int x,int a){
	int res=1;
	while(a>0){
		if(a&1)res=(1LL*x*res)%P;
		x=(1LL*x*x)%P;
		a>>=1;
	}
	return res;
}
int main(){
	//int ans=(1LL*(quick(2,128))*128)%P*quick(22,P-2)%P;
	//printf("%d\n",ans);
	int j,k,b=7,ma=(1<<b);
	for(k=1;k<ma;k++){
		int tmp=0;
		for(j=k;j<(1<<b);j+=k){
			int x=j;
			while(x>0){
				tmp+=x&1;
				x>>=1;
			}
		}
		int x=k;
		j=b-1;
		while(j>=0){
			A[j]=x&1;
			x>>=1;
			j--;
		}
		for(j=0;j<b;j++)
			printf("%d",A[j]);
		int cs=(1<<(b-1))*b-tmp*k;
		//int cs2=k*cs;
		int cs3=tmp-(1<<(b-1))*b/k;
		printf("\t%d:\t%d\t%d\t%d\n",k,tmp,cs,cs3);
	}
	return 0;
}
