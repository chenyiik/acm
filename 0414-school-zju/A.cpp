#include<cstdio>
#include<algorithm>
#define M 100005
using namespace std;
int A[2][M],B[2][M];
int a[M],b[M],p[2],q[2];
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		p[0]=p[1]=q[0]=q[1]=0;
		int i,j,n,m,x,ans=0;
		scanf("%d %d",&n,&m);
		for(i=1;i<=n;i++)
			scanf("%d",&a[i]);
		for(i=1;i<=m;i++)
			scanf("%d",&b[i]);
		for(i=1;i<=n;i++){
			scanf("%d",&x);
			A[x][p[x]]=a[i];
			p[x]++;
		}
		for(i=1;i<=m;i++){
			scanf("%d",&x);
			B[x][q[x]]=b[i];
			q[x]++;
		}
		/*
		for(i=0;i<p[0];i++)
			printf("%d ",A[0][i]);
		puts("");
		for(i=0;i<p[1];i++)
			printf("%d ",A[1][i]);
		puts("");
		for(i=0;i<q[0];i++)
			printf("%d ",B[0][i]);
		puts("");
		for(i=0;i<q[1];i++)
			printf("%d ",B[1][i]);
		puts("");*/
		sort(A[0],A[0]+p[0]);
		sort(A[1],A[1]+p[1]);
		sort(B[0],B[0]+q[0]);
		sort(B[1],B[1]+q[1]);
		i=0;j=0;
		while(i<p[0]&&j<q[1]){
			if(B[1][j]>A[0][i]){
				i++;
				continue;
			}
			ans++;
			i++;j++;
		}
		i=0;j=0;
		while(i<p[1]&&j<q[0]){
			if(A[1][i]>B[0][j]){
				j++;
				continue;
			}
			ans++;
			i++;j++;
		}
		printf("%d\n",ans);
	}
	return 0;
}
