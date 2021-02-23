#include<cstdio>
#include<algorithm>
#define LL long long
using namespace std;
int main(){
	LL mi=0,ma=0,mi2=0,ma2=0,base,d;
	int i,n;
	scanf("%d %lld %lld",&n,&d,&base);
	for(i=1;i<n;i++){
		LL tmp,tmp2;
		scanf("%lld",&tmp);
		tmp2=tmp;
		tmp=tmp-(base+d*i);
		tmp2=tmp2-(base-d*i);
		if(tmp<mi)mi=tmp;
		if(tmp>ma)ma=tmp;
		if(tmp2<mi2)mi2=tmp2;
		if(tmp2>ma2)ma2=tmp2;
	}
	if(ma2-mi2>ma-mi)
		printf("%lld.%c\n", (ma-mi)/2, "05"[(ma-mi) % 2]);
	else
		printf("%lld.%c\n", (ma2-mi2)/2, "05"[(ma2-mi2) % 2]);
	return 0;
}
