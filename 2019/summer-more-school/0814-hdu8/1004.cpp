#include<cstdio>
#include<algorithm>
using namespace std;
struct node{
	int x,y;
}mv[6][6][20];
void Init(){
	mv[3][2][0]=(node){2,1};
	mv[3][2][1]=(node){1,2};
	mv[3][2][2]=(node){3,1};
	mv[3][2][3]=(node){2,2};
	mv[3][2][4]=(node){1,1};
	mv[3][2][5]=(node){3,2};

	mv[3][3][0]=(node){2,1};
	mv[3][3][1]=(node){3,2};
	mv[3][3][2]=(node){2,3};
	mv[3][3][3]=(node){1,2};
	mv[3][3][4]=(node){3,1};
	mv[3][3][5]=(node){2,2};
	mv[3][3][6]=(node){1,3};
	mv[3][3][7]=(node){1,1};
	mv[3][3][8]=(node){3,3};

	mv[4][2][0]=(node){2,1};
	mv[4][2][1]=(node){4,1};
	mv[4][2][2]=(node){3,2};
	mv[4][2][3]=(node){1,2};
	mv[4][2][4]=(node){3,1};
	mv[4][2][5]=(node){1,1};
	mv[4][2][6]=(node){2,2};
	mv[4][2][7]=(node){4,2};

	mv[5][2][0]=(node){2,1};
	mv[5][2][1]=(node){4,2};
	mv[5][2][2]=(node){5,1};
	mv[5][2][3]=(node){3,2};
	mv[5][2][4]=(node){1,2};
	mv[5][2][5]=(node){3,1};
	mv[5][2][6]=(node){1,1};
	mv[5][2][7]=(node){2,2};
	mv[5][2][8]=(node){4,1};
	mv[5][2][9]=(node){5,2};

	mv[4][3][0]=(node){2,1};
	mv[4][3][1]=(node){4,1};
	mv[4][3][2]=(node){3,3};
	mv[4][3][3]=(node){3,1};
	mv[4][3][4]=(node){1,1};
	mv[4][3][5]=(node){1,3};
	mv[4][3][6]=(node){3,2};
	mv[4][3][7]=(node){1,2};
	mv[4][3][8]=(node){2,3};
	mv[4][3][9]=(node){4,2};
	mv[4][3][10]=(node){2,2};
	mv[4][3][11]=(node){4,3};
}
void solve(){
	int n,m,p;
	scanf("%d %d",&n,&m);
	if(n==1&&m==1){
		puts("YES\n1 1");
		return;
	}
	if((n<=2&&m<=2)||n==1||m==1){
		puts("NO");
		return;
	}
	puts("YES");
	bool inv=0;
	int i=0;
	if(m==2){
		while(n-i!=0&&n-i!=4&&n-i!=5){
			for(p=0;p<6;p++){
				node tmp=mv[3][2][p];
				tmp.x+=i;
				printf("%d %d\n",tmp.x,tmp.y);
			}
			i+=3;
		}
		if(n-i==4){
			for(p=0;p<8;p++){
				node tmp=mv[4][2][p];
				tmp.x+=i;
				printf("%d %d\n",tmp.x,tmp.y);
			}
		}else if(n-i==5){
			for(p=0;p<10;p++){
				node tmp=mv[5][2][p];
				tmp.x+=i;
				printf("%d %d\n",tmp.x,tmp.y);
			}
		}
		return;
	}
	while(n-i!=0&&n-i!=4&&n-i!=2){
		int j=0;
		while(m-j!=0&&m-j!=3){
			for(p=0;p<6;p++){
				node tmp=mv[3][2][p];
				tmp.x+=i;
				tmp.y+=j;
				if(inv)
					tmp.y=m-tmp.y+1;
				printf("%d %d\n",tmp.x,tmp.y);
			}
			j+=2;
		}
		if(m-j==3){
			for(p=0;p<9;p++){
				node tmp=mv[3][3][p];
				tmp.x+=i;
				tmp.y+=j;
				if(inv)
					tmp.y=m-tmp.y+1;
				printf("%d %d\n",tmp.x,tmp.y);
			}
		}
		inv=!inv;
		i+=3;
	}
	if(n-i==2){
		int j=0;
		while(m-j!=0&&m-j!=4&&m-j!=5){
			for(p=0;p<6;p++){
				node tmp=mv[3][2][p];
				swap(tmp.x,tmp.y);
				tmp.x+=i;
				tmp.y+=j;
				if(inv)
					tmp.y=m-tmp.y+1;
				printf("%d %d\n",tmp.x,tmp.y);
			}
			j+=3;
		}
		if(m-j==4){
			for(p=0;p<8;p++){
				node tmp=mv[4][2][p];
				swap(tmp.x,tmp.y);
				tmp.x+=i;
				tmp.y+=j;
				if(inv)
					tmp.y=m-tmp.y+1;
				printf("%d %d\n",tmp.x,tmp.y);
			}
		}else if(m-j==5){
			for(p=0;p<10;p++){
				node tmp=mv[5][2][p];
				swap(tmp.x,tmp.y);
				tmp.x+=i;
				tmp.y+=j;
				if(inv)
					tmp.y=m-tmp.y+1;
				printf("%d %d\n",tmp.x,tmp.y);
			}
		}
	}else if(n-i==4){
		int j=0;
		while(m-j!=0&&m-j!=3){
			for(p=0;p<8;p++){
				node tmp=mv[4][2][p];
				tmp.x+=i;
				tmp.y+=j;
				if(inv)
					tmp.y=m-tmp.y+1;
				printf("%d %d\n",tmp.x,tmp.y);
			}
			j+=2;
		}
		if(m-j==3){
			for(p=0;p<12;p++){
				node tmp=mv[4][3][p];
				tmp.x+=i;
				tmp.y+=j;
				if(inv)
					tmp.y=m-tmp.y+1;
				printf("%d %d\n",tmp.x,tmp.y);
			}
		}
	}
}
int main(){
	int T;
	scanf("%d",&T);
	Init();
	while(T--)solve();
	return 0;
}
