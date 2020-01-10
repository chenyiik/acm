#include<cstdio>
#include<algorithm>
#define LL long long
#define M 100005
#define SM 4005
using namespace std;
LL f[SM];
struct node{
	int hp,atk;
}A[M];
void Init(){
	for(int i=1;i<SM;i++)
		f[i]=f[i-1]+i;
}
bool cmp(node a,node b){
	return 1LL*a.atk*b.hp>1LL*b.atk*a.hp;
}
LL solve(int n){
	LL ans=0,ma=0;
	int i;
	for(i=1;i<=n;i++){
		scanf("%d %d",&A[i].hp,&A[i].atk);
		A[i].hp=lower_bound(f,f+SM,A[i].hp)-f;
		ma+=A[i].atk;
	}
	sort(A+1,A+1+n,cmp);
	for(i=1;i<=n;i++){
		ans+=1LL*A[i].hp*ma;
		ma-=A[i].atk;
	}
	return ans;
}
int main(){
	int T;
	Init();
	scanf("%d",&T);
	for(int cas=1;cas<=T;cas++){
		int n;
		scanf("%d",&n);
		printf("Case #%d: %lld\n",cas,solve(n));
	}
	return 0;
}
