#include<cstdio>
#define M 1005
int A[M],B[M];
int main(){
	int i,n;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		scanf("%d %d",&A[i],&B[i]);
	for(int ans=n;ans>=0;ans--){
		int cnt=0;
		for(i=1;i<=n;i++){
			if(ans>=A[i]&&ans<=B[i]){
				cnt++;
			}
		}
		if(cnt==ans){
			printf("%d\n",ans);
			return 0;
		}
	}
	puts("-1");
	return 0;
}
