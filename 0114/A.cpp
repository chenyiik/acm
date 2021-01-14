#include<cstdio>
int main(){
	double n;
	scanf("%lf",&n);
	n=n/100+25;
	if(n<100)n=100;
	if(n>2000)n=2000;
	printf("%.2f\n",n);
	return 0;
}
