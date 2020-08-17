#include<cstdio>
#include<algorithm>
#define LL long long
#define M 5000005
using namespace std;
int n,p,q,m,tot=0;
LL ans;
unsigned int SA,SB,SC;
int S[M],S2[M];
int tp;
unsigned int rng61(){
	SA^=SA<<16;
	SA^=SA>>5;
	SA^=SA<<1;
	unsigned int t=SA;SA=SB;
	SB=SC;
	SC^=t^SA;
	return SC;
}
void PUSH(int x){
	//printf("PUSH %d\n",x);
	S[tp++]=x;
	S2[tp]=max(x,S2[tp-1]);
	int ai=S2[tp];
	ans^=1LL*tot*ai;
}
void POP(){
	if(tp>0){
		tp--;
		int ai=S2[tp];
		ans^=1LL*tot*ai;
	}
}
void gen(){
	tp=0;
	tot=0;
	ans=0;
	scanf("%d%d%d%d%u%u%u",&n,&p,&q,&m,&SA,&SB,&SC);
	for(int i=1;i<=n;i++){
		tot++;
		if((int)(rng61()%(p+q))<p)
			PUSH(rng61()%m+1);
		else
			POP();
	}
}
int main(){
	int T;
	scanf("%d",&T);
	for(int cas=1;cas<=T;cas++){
		gen();
		printf("Case #%d: %lld\n",cas,ans);
	}
	return 0;
}
