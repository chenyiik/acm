#include<cstdio>
#include<ctime>
#include<cstdlib>
int main(){
	srand(time(NULL));
	int n=10;
	printf("%d\n",n);
	for(int i=0;i<n;i++)
		printf("%d ",rand()%50-10);
	puts("");
	return 0;
}
