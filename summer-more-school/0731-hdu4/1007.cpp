#include<cstdio>
#define M 20
int A[M];
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		int i,j,x,y,dis;
		for(i=0;i<16;i++){
			scanf("%d",&A[i]);
			if(A[i]==0){
				x=i/4;
				y=i%4;
				dis=6-x-y;
				A[i]=16;
			}
		}
		int tmp=0;
		for(i=0;i<16;i++)
			for(j=i+1;j<16;j++)
				if(A[i]>A[j])tmp++;
		puts((tmp+dis)&1?"No":"Yes");
	}
	return 0;
}
