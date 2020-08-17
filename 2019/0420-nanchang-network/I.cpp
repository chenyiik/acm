#include<bits/stdc++.h>
using namespace std;
struct node
{
	long long wh,val;
	node(long long _wh=0,long long _val=0):wh(_wh),val(_val){};
	bool operator<(node _t) {return val<_t.val;}
	bool operator==(node _t) {return val==_t.val;}
	bool operator>(node _t) {return val>_t.val;}
};
stack<node> s;
long long sum[500050];
long long a[500050];
long long n;
long long min(long long a,long long b,long long c)
{
	return min(min(a,b),c);
}
int main()
{
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>n;
	sum[0]=0;
	for (long long i=1;i<=n;i++) 
	{
		cin>>a[i];
		sum[i]=sum[i-1]+a[i];
	}
	s.push(node(1,a[1]));
	long long ans=0;
	for (long long i=100;i<=n;i++) 
	{
		long long minn=2147483647;
		for (int j=1;j<=99;j++) 
		if (a[i-j]<minn) minn=a[i-j];
		long long sum=0
	for (long long r=2;r<=n;r++)
	{
		auto tmp=s.top();
		auto cur=node(r,a[r]);
		auto ss=s;
		while (!ss.empty())
		{
			auto tmp=ss.top();ss.pop();
			long long tmpd=(sum[r-1]-sum[tmp.wh-1])*tmp.val;
			if (tmpd>ans) ans=tmpd;
		}
		//if (tmp==cur) continue;
		if (tmp<cur||tmp==cur) {s.push(cur);continue;}
		while (tmp>cur)
		{
			long long tmpd=(sum[r-1]-sum[tmp.wh-1])*tmp.val;
			if (tmpd>ans) ans=tmpd;
			cur.wh=tmp.wh;
			s.pop();
			if (s.empty()) break;
			tmp=s.top();
		}
		s.push(cur);
	}
	while (!s.empty())
	{
		auto tmp=s.top();s.pop();
		long long tmpd=(sum[n]-sum[tmp.wh-1])*tmp.val;
		if (tmpd>ans) ans=tmpd;
	}
	cout<<ans<<endl;
	return 0;
}
	
	
	
