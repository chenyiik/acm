include<bits/stdc++.h>
#define M 255
using namespace std;
string s=string()+
"UDRRIRLLLLLRUIRLLLDDRDDRLLR"+
"RDRRIRLLLIIRUIRLLLDDRDDRLLR"+
"UURUURUURUURUURUURUURUURUUR"+
"PPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPP"+
"PPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPP";
int dat[M][M];
int mark[M][M];
int mx[]={-1,0,1,0};
int my[]={0,1,0,-1};
int random(int L,int R){
	return 1.0*rand()/RAND_MAX*(R-L)+L;
}
int main(){
	/*
	//freopen("D.txt","w",stdout);
	srand(time(NULL));
	rand();
	int tot=0;
	int tp=10;
	double ft=0;
	for(int cas=0;cas<tp;cas++){
		tot=0;
		int T=1000;
		int cnt=0;
		int i,j;
		int n=12,m=12,x=2,y=2,k=200;
		for(i=1;i<=n;i++)
			for(j=1;j<=m;j++)
				dat[i][j]=1;
		while(T--){
			x=2;y=2;k=200;
			for(i=2;i<n;i++)
				for(j=2;j<m;j++)
					dat[i][j]=0;
			for(i=1;i<=50;i++){
				int a=random(2,n-1);
				int b=random(2,m-1);
				while(dat[a][b]==2){
					a=random(2,n-1);
					b=random(2,m-1);
				}
				dat[a][b]=2;
			}
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
		ft+=tot;
		//cout<<tot<<endl;
	}
	cout<<ft/tp<<endl;
	*/
	cout<<s<<endl;

	return 0;
}

