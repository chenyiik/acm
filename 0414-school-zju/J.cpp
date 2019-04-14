#include<cstdio>
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		long long n;
		scanf("%lld",&n);
		if(n&1)
			printf("%lld %lld\n",9LL,9+n);
		else
			printf("%lld %lld\n",4LL,4+n);
	}
	return 0;
}
