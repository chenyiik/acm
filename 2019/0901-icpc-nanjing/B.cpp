#include<cstdio>
const int maxn=1000000+10,maxp=int(7e5);
int phi[maxn],prime[maxp],pn=0;
bool is_p[maxn+5];
void phi_table(int n){
	phi[1]=1;
	for(int i=2;i<=n;i++)
		phi[i]=0;
	for(int i=2;i<=n;i++)
	{
		if(!is_p[i])
		{
			prime[pn++]=i;
			phi[i]=i-1;
		}
		for(int j=0;j<pn&&i*prime[j]<=n;j++)
		{
			is_p[i*prime[j]]=true;
			if(i%prime[j]==0)
				phi[i*prime[j]]=phi[i]*prime[j],j=pn;
			else
				phi[i*prime[j]]=phi[i]*(prime[j]-1);
		}
	}
}
int quick(int x,int a,int m){
	int res=1;
	while(a>0){
		if(a&1)res=(1LL*res*x)%m;
		a>>=1;
		x=1LL*x*x%m;
	}
	return res;
}
int gcd(int a,int b){return b?gcd(b,a%b):a;}
int gcd(int a,int b,int &d,int &x,int &y){
	if(!b)
		d=a,x=1,y=0;
	else{
		gcd(b,a%b,d,y,x);
		y-=x*(a/b);
	}
	return -1;
}
int inv(int a,int n){
	int d,x,y;
	gcd(a,n,d,x,y);
	return d==1?(x+n)%n:-1;
}
int f(int a,int b,int m){
	printf("\t%d %d %d %d\n",a,b,m,phi[m]);
	if(m==1)
		return 0;
	if(b==0)
		return 1%m;
	if(b==1)
		return a%m;
	int ans;
	int d=gcd(a,m);
	if(d==1) 
		ans=quick(a,f(a,b-1,phi[m]),m);
	else
		ans=1LL*quick(a,f(a,b-1,phi[m/d]),m/d)*d%m;
	return ans;
}
int main(){
	phi_table(maxn-5);
	int T;
	scanf("%d",&T);
	while(T--){
		int a,b,m;
		scanf("%d %d %d",&a,&b,&m);
		puts("");
		printf("%d\n",f(a,b,m));
	}
	return 0;
}
