#include<cstdio>
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		int n;
		scanf("%d",&n);
		while(1){
			if(n%7==0){
				if(n%4!=0){
					printf("%d\n",n);
					break;
				}
			}
			n++;
		}
	}
}
