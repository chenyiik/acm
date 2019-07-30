#include<bits/stdc++.h>
#define M 255
using namespace std;
char s[M];
int dat[M][M];
int mark[M][M];
int mx[]={-1,0,1,0};
int my[]={0,1,0,-1};
int main(){
	//freopen("D.txt","w",stdout);
	srand(time(NULL));
	rand();
	int tot=0;
	while(1){
		tot=0;
		int T=1000;
		int cnt=0;
		int i,j;
		int n=12,m=12,x=2,y=2,k=200;
		for(i=0;i<81;i++){
			string str="";
			int rr=i%3;
			int ll=i/3%3;
			int dd=i/9%3;
			int uu=i/27%3;
			if(rr!=1)str+="R";
			if(ll!=1)str+="L";
			if(dd!=1)str+="D";
			if(uu!=1)str+="U";
			if(str.length()==0){
				s[i]='P';
				continue;
			}
			s[i]=str[rand()%str.length()];
		}
		for(i=81;i<243;i++)
			s[i]='P';
		for(i=1;i<=n;i++)
			for(j=1;j<=m;j++)
				dat[i][j]=1;
		while(T--){
			x=2;y=2;k=200;
			for(i=2;i<n;i++)
				for(j=2;j<m;j++)
					dat[i][j]=0;
			for(i=1;i<=50;i++){
				int a=rand()%(n-2)+2;
				int b=rand()%(m-2)+2;
				while(dat[a][b]==2){
					a=rand()%(n-2)+2;
					b=rand()%(m-2)+2;
				}
				dat[a][b]=2;
			}
			/*
			for(i=1;i<=n;i++)
				for(j=1;j<=m;j++)
					printf("%d%c",dat[i][j]," \n"[j==m]);
					*/
			int ans=0;
			cnt++;
			while(k--){
				char op=s[81*(dat[x][y])+27*(dat[x-1][y])+9*(dat[x+1][y])+3*(dat[x][y-1])+(dat[x][y+1])];
				if(op=='P'){
					if(dat[x][y]!=2)
						break;
					dat[x][y]=0;
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
					if(dat[nx][ny]==1||cnt==mark[nx][ny])
						break;
					x=nx;
					y=ny;
					mark[nx][ny]=cnt;
				}
			}
			tot+=ans;
		}
		if(tot>=47500)
			break;
		if(tot>15000)
			printf("%d:%s\n",tot,s);
	}
	printf("%d:%s\n",tot,s);

	return 0;
}
