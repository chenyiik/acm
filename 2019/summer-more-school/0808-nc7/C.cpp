#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<unordered_map>
#define LL long long
#define M 100005
#define SM 205
using namespace std;
void Rd(int &res){
	res=0;
	char c;
	while(c=getchar(),!isdigit(c));
	do{
		res=(res*10)+(c^48);
	}while(c=getchar(),isdigit(c));
}
unordered_map<int,LL>C,P;
int n;
LL CX[SM];
int H[M];
struct node{
	int h,c,p;
}A[M];
LL calc(int h,LL cnt,LL mx){
	LL ans=0;
	int i=1;
	while(A[n].h==h&&n>0){
		CX[A[n].c]-=A[n].p;
		n--;
	}
	if(cnt<mx*2)return 0;
	while(i<=200){
		if(cnt-CX[i]<mx*2){
			ans+=1LL*(cnt-mx*2+1)*i;
			break;
		}
		ans+=1LL*i*CX[i];
		cnt-=CX[i];
		i++;
	}
	return ans;
}
LL dfs(int t,LL cnt){
	if(t==0)return 0;
	LL PHt=P[H[t]];
	LL aans=calc(H[t],cnt,PHt);
	if(aans==0)return 0;
	return min(aans,C[H[t]]+dfs(t-1,cnt-PHt));
}
bool cmp(node a,node b){
	return a.h<b.h;
}
int main(){
	while(scanf("%d",&n)!=EOF){
		int tp=0;
		int h,c,p;
		C.clear();
		P.clear();
		memset(CX,0,sizeof(CX));
		int i;
		LL cnt=0;
		for(i=1;i<=n;i++){
			Rd(h),Rd(c),Rd(p);
			A[i].h=h;
			A[i].c=c;
			A[i].p=p;
			CX[c]+=p;
			C[h]+=1LL*c*p;
			P[h]+=p;
			cnt+=p;
			H[tp++]=h;
		}
		sort(A+1,A+1+n,cmp);
		sort(H,H+tp);
		tp=unique(H,H+tp)-H;
		cout<<dfs(tp-1,cnt)<<endl;
	}
	return 0;
}
