#include<cstdio>
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		int n;
		int ans;
		scanf("%d",&n);
		switch(n){
			case 1:
				ans=2;
				break;
			case 2:
				ans=16;
				break;
			case 3:
				ans=32;
				break;
			default:
				ans=4;
				break;
		}
		printf("%d\n",ans);
	}
	return 0;
}
