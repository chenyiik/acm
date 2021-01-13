#include<cstdio>
bool mark[1000];
int main(){
	int n;
	scanf("%d",&n);
	do{
		if(n<1000) mark[n]=1;
		int tmp=n,sum=0;
		while(tmp!=0){
			int d=tmp%10;
			sum+=d*d;
			tmp/=10;
		}
		n=sum;
		if(n==1)break;
	}while(!mark[n]);
	if(n==1)puts("HAPPY");
	else puts("UNHAPPY");
	return 0;
}
