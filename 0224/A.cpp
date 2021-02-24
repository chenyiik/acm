#include<cstdio>
#define M 100005
int A[M],cnt[M];
int main(){
	int i,n,m;
	scanf("%d %d",&n,&m);
	for(i=1;i<=n;i++)
		scanf("%d",&A[i]);
	while(m--){
		int L,R;
		scanf("%d %d",&L,&R);
		if(L<R){
			for(i=L;i<=R;i++)
				cnt[A[i]]++;
			int p=L;
			for(i=1;i<=n;i++){
				if(cnt[i]){
					cnt[i]--;
					A[p++]=i;
					if(p>R)break;
				}
			}
		}else{
			for(i=L;i<=R;i++)
				cnt[A[i]]++;
			int p=L;
			for(i=n;i>0;i--){
				if(cnt[i]){
					cnt[i]--;
					A[p++]=i;
					if(p>R)break;
				}
			}
		}
	}
	printf("%d\n",A[n/2+1]);
	return 0;
}
