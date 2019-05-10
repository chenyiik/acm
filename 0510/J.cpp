#include<cstdio>
int main(){
	int n,s,ma=-1;
	scanf("%d %d",&n,&s);
	while(n--){
		int tmp;
		scanf("%d",&tmp);
		if(tmp>ma)ma=tmp;
	}
	ma*=s;
	printf("%d\n",(ma+(999))/1000);
	return 0;
}
