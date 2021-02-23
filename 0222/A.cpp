#include<cstdio>
#include<algorithm>
#define M 100005
#define S 20
using namespace std;
int H[M];
int fa[M][S];
int main(){
	int i,j,n;
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%d",&H[i]);
		fa[i-1][0]=max(H[i-1],H[i]);
	}
	fa[n][0]=H[n];
	for(i=1;i<S;i++){
		for(j=1;j<=n;j++){
			if(j+(1<<(i-1))<=n)
				fa[j][i]=max(fa[j][i-1],fa[j+(1<<(i-1))][i-1]);
			else
				fa[j][i]=fa[j][i-1];
		}
	}
	for(i=1;i<=n;i++){
		int x=i;
		j=S-1;
		while(j>=0){
			if(x+(1<<j)<=i+H[i]&&fa[x][j]<=H[i])
				x=min(x+(1<<j),n);
			j--;
		}
		printf("%d%c",x-i," \n"[i==n]);
	}
	return 0;
}
