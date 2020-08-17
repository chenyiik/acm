#include<bits/stdc++.h>
using namespace std;
const long long mod=1e9+7;
long long qpow(long long a,long long b)
{
	long long ans=1;
	while (b)
	{
		if (b%2) ans=(ans*a)%mod;
		a=(a*a)%mod;
		b/=2;
	}
	return ans;
}
int main() 
{
	long long T;
	cin>>T;
	long long ans=1; 
	while (T--)
	{
		long long n,m;
		cin>>n>>m;
		if (n==1) {cout<<ans<<endl;continue;}
		if (m==0) {cout<<(ans=0)<<endl;continue;}
		cout<<(ans=(ans*qpow(n-1,mod-2))%mod)<<endl;
	}
}

