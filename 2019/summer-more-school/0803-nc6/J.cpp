#include<cstdio>
#include<iostream>
#include<algorithm>
#define M 1005
#define LL long long
using namespace std;
int C[M][M];
LL pre[M][M];
int nxt[M][M];
int D[M];
int p[M];
int main(){
	int cas,T;
	scanf("%d",&T);
	for(cas=1;cas<=T;cas++){
		int i,j,n,m;
		LL ans=0;
		scanf("%d %d",&n,&m);
		for(i=1;i<=n;i++)
			for(j=1;j<=m;j++){
				scanf("%d",&C[i][j]);
				pre[i][j]=pre[i][j-1]+C[i][j];
				ans-=C[i][j];
			}
		for(i=1;i<=m;i++){
			scanf("%d",&D[i]);
			ans+=D[i];
		}
		ans=max(ans,0LL);
		for(i=1;i<=n;i++){
			nxt[i][m]=m+1;
			LL mp=m;
			for(j=m-1;j>=0;j--){
				if(pre[i][j]<=pre[i][mp])mp=j;
				nxt[i][j]=mp;
			}
		}
		/*for(i=1;i<=n;i++){
			for(j=0;j<=m;j++)
				printf("%d%c",nxt[i][j]," \n"[j==m]);
		}*/
		LL sum=0;
		for(j=0;j<m;j++){
			sum+=D[j];
			int loc=1;
			LL tmp=0;
			for(i=1;i<=n;i++){
				sum-=C[i][j];
				tmp-=pre[i][nxt[i][j]]-pre[i][j];
				if(pre[i][nxt[i][j]]-pre[i][j]>pre[loc][nxt[loc][j]]-pre[loc][j])loc=i;
			}
			tmp+=pre[loc][nxt[loc][j]]-pre[loc][j];
			ans=max(ans,sum+tmp);
		}
		cout<<"Case #"<<cas<<": "<<ans<<endl;
	}
	return 0;
}
