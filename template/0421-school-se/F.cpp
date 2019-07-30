#include<bits/stdc++.h>
#define M 19
using namespace std;
void Rd(int &res){
	res=0;
	char c;
	while(c=getchar(),!isdigit(c));
	do{
		res=(res*10)+(c^48);
	}while(c=getchar(),isdigit(c));
}
int dat[M][M],cnt[M][1<<M],tp[1<<M];
bool mark[M];
int dp[1<<M];
int main(){
	int i,j,T;
	Rd(T);
	memset(tp,0x3f,sizeof(tp));
	for(i=0;i<(1<<(M-1));i++){
		for(j=0;j<M-1;j++)
			if(i&(1<<j)){
				tp[i]=j;
				break;
			}
	}
	while(T--){
		int n,m;
		memset(dat,0,sizeof(dat));
		memset(mark,0,sizeof(mark));
		Rd(n);
		Rd(m);
		for(i=1;i<=n;i++){
			int a,b;
			Rd(a),Rd(b);
			dat[a-1][b-1]++;
		}
		for(i=0;i<m;i++)
			for(j=0;j<m;j++)
				dat[i][m]+=dat[i][j];
		for(i=0;i<m;i++)
			if(dat[i][m]==dat[i][i])
				mark[i]=1;
		for(i=0;i<(1<<m);i++){
			dp[i]=n*m;
			for(j=0;j<m;j++)
				cnt[j][i]=0;
		}
		dp[0]=0;
		for(j=0;j<m;j++){
			for(i=0;i<(1<<m);i++){
				int k=tp[i];
				if(k>m)continue;
				int nxt=i^(1<<k);
				cnt[j][i]=cnt[j][nxt]+dat[k][j];
			}
		}
		for(i=0;i<(1<<m);i++){
			for(j=0;j<m;j++){
				if(!(i&(1<<j))){
					int nxt=i|(1<<j);
					if(mark[j])
						dp[nxt]=min(dp[nxt],dp[i]);
					else
						dp[nxt]=min(dp[nxt],dp[i]+cnt[j][i]+dat[j][m]);
				}
			}
		}
		printf("%d\n",dp[(1<<m)-1]);
	}
	return 0;
}
