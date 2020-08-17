#include<bits/stdc++.h>
#define sqr(x) ((x)*(x))
using namespace std;
long long gcd(long long a,long long b)
{
	while (b^=a^=b^=a%=b);
	return a;
}
int main()
{
	ios::sync_with_stdio(0);cin.tie(0);
	long long n,m;
	while(cin>>n>>m)
	{
		static long long a[10050];
		for (long long i=1;i<=n;i++) cin>>a[i];
		sort(a+1,a+n+1,greater<long long>());
		long long tag=n,r=m;
		for (long long i=1;i<n;i++)
		{
			if (i*abs(a[i+1]-a[i])>r) {tag=i;break;}
			r-=i*abs(a[i+1]-a[i]);
		}
		long long ans=sqr(a[tag]*tag-r);
		for (int i=tag+1;i<=n;i++) ans+=sqr(a[i]);
		long long fm=m*m*tag;
		auto x=gcd(ans,fm);
		if (fm==1||ans==0) {cout<<ans<<endl;continue;}
		cout<<ans/x<<"/"<<fm/x<<endl;
	}
	return 0;
}
