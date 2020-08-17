#include <stdio.h>
int main() {
	int n,m,x; scanf("%d%d",&n,&m);
	while(~scanf("%d",&x)) n-=2*(x<m);
	printf("%d\n",(n<0?0:n));
}
