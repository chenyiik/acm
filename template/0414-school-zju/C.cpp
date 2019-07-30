#include<bits/stdc++.h>
#define M 2005
using namespace std;
char s[M],dat[M][M];
int mark[M][M];
int mx[]={-1,0,1,0};
int my[]={0,1,0,-1};
int main(){
	int T;
	int cnt=0;
	scanf("%d",&T);
	while(T--){
		cnt++;
		int i,n,m,x,y,k,ans=0;
		scanf("%d %d %d %d %d %s",&n,&m,&x,&y,&k,s);
		for(i=1;i<=n;i++)
			scanf("%s",dat[i]+1);
		while(k--){
			char op=s[81*(dat[x][y]-'0')+27*(dat[x-1][y]-'0')+9*(dat[x+1][y]-'0')+3*(dat[x][y-1]-'0')+(dat[x][y+1]-'0')];
			if(op=='P'){
				if(dat[x][y]!='2')
					break;
				dat[x][y]='0';
				ans++;
				cnt++;
			}else if(op=='I'){
				break;
			}else{
				int dir;
				if(op=='U')
					dir=0;
				if(op=='R')
					dir=1;
				if(op=='D')
					dir=2;
				if(op=='L')
					dir=3;
				int nx=x+mx[dir];
				int ny=y+my[dir];
				if(dat[nx][ny]=='1'||cnt==mark[nx][ny])
					break;
				x=nx;
				y=ny;
				mark[nx][ny]=cnt;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
