#include<cstdio>
#define P 1000000007
int quick(int x,int a){
	int res=1;
	while(a>0){
		if(a&1)res=(1LL*res*x)%P;
		x=1LL*x*x%P;
		a>>=1;
	}
	return res;
}
int main(){
	int n;
	scanf("%d",&n);
	if(n==1){
		puts("1");
		return 0;
	}
	printf("%d\n",(int)(4LL*quick(3,n-2)%P));
	return 0;
}

