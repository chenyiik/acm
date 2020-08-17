#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#define M 20005
#define EPT 10360019
#define eps 1e-15
using namespace std;
double sur[M];
int chess[6][6];//0=. or #  1=White 2=Black 
int shadow[6][6];
char str[10][10];
bool equal(double a,double b){
	return fabs(a-b)<eps;
}
void Prt(int t){
	for(int i=1;i<=3;i++){
		for(int j=0;j<t;j++)
			printf("\t");
		for(int j=1;j<=3;j++){
			char c;
			if(chess[i][j]==0)c='.';
			if(chess[i][j]==1)c='O';
			if(chess[i][j]==2)c='X';
			putchar(c);
		}
		puts("");
	}
	puts("");
}
int hsh(){
	int tmp=0;
	for(int i=3;i>=1;i--)
		for(int j=3;j>=1;j--)
			tmp=tmp*3+chess[i][j];
	return tmp;
}
double calc(double L,double R){
	//printf("\t%lf %lf ",L,R);
	bool LE=equal(L,EPT);
	bool RE=equal(R,EPT);
	if(LE){
		if(RE)return 0;
		return R-1;
	}
	if(RE)return L+1;
	int multi=1;
	while((R-L)*multi<1||equal((R-L)*multi,1))
		multi<<=1;
	//printf("%d ",multi);
	if(fabs(L*multi)<fabs(R*multi)||equal(fabs(L*multi),fabs(R*multi)))
		return ceil(L*multi+1e-10)/multi;
	return floor(R*multi-1e-10)/multi;
}
double alice(int x,int y){
	shadow[x][y]=chess[x][y];
	shadow[x-1][y]=chess[x-1][y];
	shadow[x+1][y]=chess[x+1][y];
	shadow[x][y-1]=chess[x][y-1];
	shadow[x][y+1]=chess[x][y+1];
	chess[x][y]=chess[x-1][y]=chess[x+1][y]=chess[x][y-1]=chess[x][y+1]=0;
	//Prt(1);
	double rt=sur[hsh()];
	//printf("%d ",hsh());
	chess[x-1][y]=shadow[x-1][y];
	chess[x+1][y]=shadow[x+1][y];
	//Prt(2);
	double rt2=sur[hsh()];
	//printf("%d ",hsh());
	chess[x-1][y]=chess[x+1][y]=0;
	chess[x][y-1]=shadow[x][y-1];
	chess[x][y+1]=shadow[x][y+1];
	//Prt(3);
	double rt3=sur[hsh()];
	//printf("%d ",hsh());
	chess[x-1][y]=shadow[x-1][y];
	chess[x][y]=shadow[x][y];
	chess[x+1][y]=shadow[x+1][y];
	//printf("%lf %lf %lf\n",rt,rt2,rt3);
	return max(rt,max(rt2,rt3));
}
double bob(int x,int y){
	shadow[x][y]=chess[x][y];
	chess[x][y]=0;
	double rt=sur[hsh()];
	chess[x][y]=shadow[x][y];
	return rt;
}
void Init(){
	int i,j,k;
	for(i=0;i<M;i++)
		sur[i]=EPT;
	sur[0]=0;
	for(k=1;k<19683;k++){
		int x=k;
		for(i=1;i<=3;i++)
			for(j=1;j<=3;j++){
				chess[i][j]=x%3;
				x/=3;
			}
		//Prt(0);
		double XL=EPT,XR=EPT;
		for(i=1;i<=3;i++)
			for(j=1;j<=3;j++){
				if(chess[i][j]==1){
					double tmp=alice(i,j);
					if(equal(XL,EPT)||tmp>XL)
						XL=tmp;
				}
				if(chess[i][j]==2){
					double tmp=bob(i,j);
					if(equal(XR,EPT)||tmp<XR)
						XR=tmp;
				}
			}
		sur[k]=calc(XL,XR);
		//printf("%lf\n",sur[k]);
		//system("PAUSE");
	}
}
int main(){
	int T;
	Init();
	scanf("%d",&T);
	while(T--){
		int i,j,n;
		double ans=0;
		scanf("%d",&n);
		while(n--){
			for(i=1;i<=3;i++)
				scanf("%s",str[i]+1);
			for(i=1;i<=3;i++)
				for(j=1;j<=5;j+=2){
					if(str[i][j]=='O')chess[i][(j+1)/2]=1;
					else if(str[i][j]=='X')chess[i][(j+1)/2]=2;
					else chess[i][(j+1)/2]=0;
				}
			ans+=sur[hsh()];
		}
		if(equal(ans,0))puts("Second");
		else if(ans<0)puts("Bob");
		else puts("Alice");
	}
	return 0;
}
