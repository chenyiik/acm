#include<bits/stdc++.h>
using namespace std;
inline void readint(long long &res)
{
	res=0;
	char c;
	while(c=getchar(),!isdigit(c));
	do{
		res=res*10+c^48;
	}while(c=getchar(),isdigit(c));
}
int main()
{
	long long n,m,q;readint(n),readint(m),readint(q);
	static long long x[1000050];
	for (long long i=1;i<=n;i++) readint(x[i]);
	while (q--)
	{
		long long p,k;
		readint(p),readint(k);
		long long wh=p*x[k];
		long long twh=wh/m;
		wh=wh%m;
		if (twh&1) wh=m-wh;
		printf("%lld\n",wh);
	}
}

