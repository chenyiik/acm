#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
double calc(double a,double b,double c,double d){
	return sqrt((a-c)*(a-c)+(b-d)*(b-d));
}
int main(){
	int x,y,x1,y1,x2,y2;
	double ans;
	scanf("%d %d %d %d %d %d",&x,&y,&x1,&y1,&x2,&y2);
	int a,b;
	if(x<x1)a=-1;
	else if(x>=x1&&x<=x2)a=0;
	else a=1;
	if(y<y1)b=-1;
	else if(y>=y1&&y<=y2)b=0;
	else b=1;
	if(a<0){
		if(b<0)ans=calc(x,y,x1,y1);
		if(b==0)ans=calc(x,y,x1,y);
		if(b>0)ans=calc(x,y,x1,y2);
	}
	if(a==0){
		if(b<0)ans=calc(x,y,x,y1);
		if(b>0)ans=calc(x,y,x,y2);
	}
	if(a>0){
		if(b<0)ans=calc(x,y,x2,y1);
		if(b==0)ans=calc(x,y,x2,y);
		if(b>0)ans=calc(x,y,x2,y2);
	}
	printf("%.3lf\n",ans);
	return 0;
}
