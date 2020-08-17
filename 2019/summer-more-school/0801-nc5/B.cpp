#include<cstdio>
#include<cstring>
#define M 1000005
#define LL long long
using namespace std;
int p;
char str[M];
struct node{
	LL a[2][2];
	node(){a[0][0]=a[0][1]=a[1][0]=a[1][1]=0;}
	node operator *(const node &b)const{
		node c;
		c.a[0][0]=(1LL*a[0][0]*b.a[0][0]%p+1LL*a[0][1]*b.a[1][0]%p)%p;
		c.a[0][1]=(1LL*a[0][0]*b.a[0][1]%p+1LL*a[0][1]*b.a[1][1]%p)%p;
		c.a[1][0]=(1LL*a[1][0]*b.a[0][0]%p+1LL*a[1][1]*b.a[1][0]%p)%p;
		c.a[1][1]=(1LL*a[1][0]*b.a[0][1]%p+1LL*a[1][1]*b.a[1][1]%p)%p;
		return c;
	}
};
node quick(node x,int a){
	node res;
	res.a[0][0]=res.a[1][1]=1;
	while(a>0){
		if(a&1)res=x*res;
		a>>=1;
		x=x*x;
	}
	return res;
}
int main(){
	int i,x0,x1,a,b,len;
	scanf("%d %d %d %d %s %d",&x0,&x1,&b,&a,str,&p);
	len=strlen(str);
	node ori;
	ori.a[0][1]=a;
	ori.a[1][0]=1;
	ori.a[1][1]=b;
	node ans;
	ans.a[0][0]=ans.a[1][1]=1;
	for(i=0;i<len;i++){
		ans=quick(ans,10);
		ans=ans*quick(ori,str[i]^48);
	}
	printf("%d\n",(int)((1LL*x0*ans.a[0][0]%p+1LL*x1*ans.a[1][0]%p)%p));
	return 0;
}
