#include<cstdio>
#include<iostream>
#include<cstring>
#define M 1000005
using namespace std;
int p;
class BigNum{
	public:
		int a[M];
		int len;
		BigNum(){len=1;memset(a,0,sizeof(a));}
		friend istream& operator>>(istream&,BigNum&);
	__int128 operator% (const __int128 &b)const{
		int i;
		__int128 d=0;
		for(i=len-1;i>=0;i--)
			d=((d*10000)%b+a[i])%b;
		return d;
	}
	void mns(){
		int i;
		a[0]--;
		for(i=0;i<len;i++){
			if(a[i]<0){
				a[i+1]--;
				a[i]+=10000;
			}else{
				break;
			}
		}
		if(a[len-1]==0)len--;
	}
};
char ch[M];
istream& operator>>(istream &in,BigNum &b){
	int i=-1;
	in>>ch;
	int L=strlen(ch);
	int count=0,sum=0;
	for(i=L-1;i>=0;){
		sum=0;
		int t=1;
		for(int j=0;j<4&&i>=0;j++,i--,t*=10)
			sum+=(ch[i]-'0')*t;
		b.a[count]=sum;
		count++;
	}
	b.len=count++;
	return in;
}
struct node{
	__int128 a[2][2];
	node(){a[0][0]=a[0][1]=a[1][0]=a[1][1]=0;}
	node operator *(const node &b)const{
		node c;
		c.a[0][0]=(a[0][0]*b.a[0][0]%p+a[0][1]*b.a[1][0]%p)%p;
		c.a[0][1]=(a[0][0]*b.a[0][1]%p+a[0][1]*b.a[1][1]%p)%p;
		c.a[1][0]=(a[1][0]*b.a[0][0]%p+a[1][1]*b.a[1][0]%p)%p;
		c.a[1][1]=(a[1][0]*b.a[0][1]%p+a[1][1]*b.a[1][1]%p)%p;
		return c;
	}
};
int quick(int a,int b,__int128 n,int x0,int x1){
	node res,x;
	res.a[0][0]=res.a[1][1]=1;
	x.a[0][0]=0;
	x.a[0][1]=a;
	x.a[1][0]=1;
	x.a[1][1]=b;
	while(n>0){
		if(n&1)res=x*res;
		n>>=1;
		x=x*x;
	}
	return (res.a[0][1]*x0%p+res.a[1][1]*x1%p)%p;
}
int main(){
	int x0,x1,a,b;
	scanf("%d %d %d %d",&x0,&x1,&b,&a);
	BigNum n;
	cin>>n>>p;
	n.mns();
	/**for(int i=n.len-1;i>=0;i--)
		printf("%d ",n.a[i]);
	puts("");**/
	__int128 tp=p;
	__int128 k=n%(tp*tp-1);
	//cout<<k<<endl;
	printf("%d\n",quick(a,b,k,x0,x1));
	return 0;
}
/*
def multi(a,b,p):
	c=(((a[0][0]*b[0][0]+a[0][1]*b[1][0])%p,(a[0][0]*b[0][1]+a[0][1]*b[1][1])%p),((a[1][0]*b[0][0]+a[1][1]*b[1][0])%p,(a[1][0]*b[0][1]+a[1][1]*b[1][1])%p))
	return c
def quick(x,a,p):
	res=((1,0),(0,1))
	while(a>0):
		if(a&1):
			res=multi(x,res,p)
		a>>=1
		x=multi(x,x,p)
	return res
x0,x1,b,a=map(int,input("").split())
n,p=map(int,input("").split())
ans=quick(((0,a),(1,b)),(n-1)%(p*p-1),p)
print((x0*ans[0][1]+x1*ans[1][1])%p)
*/
