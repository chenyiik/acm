#include<cstdio>
int L[20],R[20];
int main(){
	int i,n,p;
	L[0]=0;
	R[0]=0;
	L[1]=1;
	R[1]=9;
	for(i=2;i<=9;i++){
		L[i]=L[i-1]*10;
		R[i]=R[i-1]*10+9;
	}
	scanf("%d %d",&n,&p);
	if(n<=8){
		for(i=L[n];i<=R[n];i++)
			if(i%p==0){
				printf("%d\n",i);
				return 0;
			}
		puts("T_T");
		return 0;
	}
	int x=p,cnt=0;
	while(x>0){
		cnt++;
		x/=10;
	}
	printf("%d",p);
	for(i=0;i<n-cnt;i++)
		printf("0");
	puts("");
	return 0;
}
