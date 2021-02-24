#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#define M 50
using namespace std;
int A[M],B[M];
int main(){
	int i,n,ans=0;
	scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf("%d",&A[i]);
	sort(A,A+n);
	do{
		int tmp=1000000000;
		for(i=1;i<n;i++)
			tmp=min(tmp,abs(A[i]-A[i-1]));
		if(tmp>ans){
			ans=tmp;
			memcpy(B,A,sizeof(A));
		}
	}while(next_permutation(A,A+n));
	for(i=0;i<n;i++)
		printf("%d ",B[i]);
	puts("");
	return 0;
}
