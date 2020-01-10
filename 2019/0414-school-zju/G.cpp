#include<cstdio>
#include<iostream>
#include<algorithm>
#define LL long long
#define M 100005
using namespace std;
int A[M],B[M];
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		int i,n,k,p=0,q=0,x;
		LL ans=0;
		scanf("%d %d",&n,&k);
		for(i=1;i<=n;i++){
			scanf("%d",&x);
			if(x==0)continue;
			if(x>0)
				B[q++]=x;
			else
				A[p++]=-x;
		}
		/*
		for(i=0;i<p;i++)
			printf("%d ",A[i]);
		puts("");
		for(i=0;i<q;i++)
			printf("%d ",B[i]);
		puts("");
		*/
		sort(A,A+p);
		sort(B,B+q);
		if(p==0&&q==0){
			puts("0");
			continue;
		}
		i=p-1;
		while(i>=0){
			ans+=2LL*A[i];
			i-=k;
		}
		i=q-1;
		while(i>=0){
			ans+=2LL*B[i];
			i-=k;
		}
		if(q==0||A[p-1]>B[q-1])
			ans-=A[p-1];
		else
			ans-=B[q-1];
		cout<<ans<<endl;
	}
	return 0;
}
