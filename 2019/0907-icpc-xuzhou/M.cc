#include<cstdio>
#include<algorithm>
#include <stack>
#define M 1000005
#define P 21
//#pragma comment(linker,"/STACK:1024000000,1024000000")
using namespace std;
char S[M],T[M];
char fa[M][P];
int pos(int n,int t,char x){
	//printf("%d %d %c\n",n,t,x);
	if(t>n)return -M;
    if(S[t]>=x)return t;
    for(int jp=P-1;jp>=0;jp--){
        if(fa[t][jp]<x)
            t+=1<<jp;
        if(t>n)return -M;
    }
	if(S[t+1]<x)return -M;
    return t+1;
}
int pos2(int n,int t,char x){
	if(t>n)return -M;
    if(S[t]==x)return t;
    for(int jp=P-1;jp>=0;jp--){
        if(fa[t][jp]<x)
            t+=1<<jp;
        if(t>n)return -M;
    }
    if(S[t+1]!=x)return -M;
    return t+1;
}
int dfs(int ps,int t,int n,int m){
    //printf("%d %d\n",ps,t);
	if(t>m)return max(0,n-ps+1);
    if(n-ps<m-t)return -M;
    if(ps<=0)return -M;
    int BG=pos(n,ps,T[t]+1);
    int ans=BG>0&&n-BG>=m-t?n-BG+1:-M;
    //printf("%d\n",ans);
    int EQ=pos2(n,ps,T[t]);
    //printf("EQ: %d\n",EQ);
	if(t==m&&EQ==n)return BG>0&&n-BG>=m-t?n-BG+1:-M; 
    return max(ans,EQ>0?1+dfs(EQ+1,t+1,n,m):-M);
}
struct R { int _ps, _t, _n, _m, _EQ, _BG; };
stack<R> St;
int _ans;
int f(int __ps, int __t, int __n, int __m)
{
	St.push({__ps, __t, __n, __m, 0, 0});
	bool flag = true;
	while (flag)
	{
		R u = St.top();
		int ps = u._ps, t = u._t, n = u._n, m = u._m;
		if(t>m)_ans=max(0,n-ps+1),flag=false;
		if (!flag){ St.pop(); break; }
		if(n-ps<m-t) _ans = -M, flag = false;
		if (!flag){ St.pop(); break; }
		if(ps<=0) _ans = -M, flag = false;
		if (!flag){ St.pop(); break; }
		int BG=pos(n,ps,T[t]+1);
		//printf("\t%d\n",BG);
		St.top()._BG = BG;
		//printf("\t\t%d\n",_ans);
		if (!flag){ St.pop(); break; }
		//printf("\t\t%d\n",_ans);
		int EQ=pos2(n,ps,T[t]);
		if(t==m&&EQ==n)(_ans=BG>0&&n-BG>=m-t?n-BG+1:-M),flag = false;
		if (!flag){ St.pop(); break; }
		St.top()._EQ = EQ;
		St.push({EQ+1,t+1,n,m,0,0});
		//return max(ans,EQ>0?1+dfs(EQ+1,t+1,n,m):-M);
	}
	while (!St.empty())
	{
		R u = St.top(); St.pop();
		int ps = u._ps, t = u._t, n = u._n, m = u._m, EQ = u._EQ, BG = u._BG;
		_ans = max((BG>0&&n-BG>=m-t?n-BG+1:-M),EQ>0?1+_ans:-M);
	}
	return _ans;
}
int main(){
    int i,j,n,m;
    scanf("%d %d %s %s",&n,&m,S+1,T+1);
    for(i=1;i<=n;i++)
        fa[i][0]=max(S[i],S[i+1]);
    for(j=1;j<P;j++)
        for(i=1;i<=n;i++){
			int k;
			if(i+(1<<(j-1))>n)k=n;
			else k=i+(1<<(j-1));
            fa[i][j]=max(fa[i][j-1],fa[k][j-1]);
		}
    printf("%d\n",max(-1,f(1,1,n,m)));
    //printf("%d\n",max(-1,dfs(1,1,n,m)));
    return 0;
}

