#include<cstdio>
#define LL long long
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		LL a,b;
		LL ans=0;
		scanf("%lld %lld",&a,&b);
		ans=(a&b);
		if(ans==0){
			LL tmp=a^b;
			for(int i=0;i<32;i++)
				if((tmp&(1LL<<i))!=0){
					ans=1LL<<i;
					break;
				}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
