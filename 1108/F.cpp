#include<bits/stdc++.h>
using namespace std;
long long s[100050],s1[100050],n,cnt,tmp[100050];
void invmerge(long long x,long long y)
{
	if (y-x>1)
	{
		long long m=x+(y-x)/2;
		long long p=x,q=m,i=x;
		invmerge(x,m);
		invmerge(m,y);
		while (p<m||q<y)
			if (q>=y||(p<m && s1[p]<=s1[q])) tmp[i++]=s1[p++];else {tmp[i++]=s1[q++];cnt+=m-p;}
		for (i=x;i<y;i++) s1[i]=tmp[i];
	}
}			
int main()
{
	ios::sync_with_stdio(0);
	long long t;cin>>t;
	while (t--)
	{
		cin>>n;
		for (long long i=1;i<=n;i++) cin>>s[i],s1[i]=s[i];
		cnt=0;
		invmerge(1,n+1);
		long long ans=cnt;
		long long m;cin>>m;
		while (m--)
		{
			long long l,r;cin>>l>>r;
			for (long long i=l+1;i<r;i++) 
			{
				if (s[i]>s[l]) cnt++;
				if (s[i]<s[l]) cnt--;
				if (s[i]<s[r]) cnt++;
				if (s[i]>s[r]) cnt--;
			}
			if (s[l]<s[r]) cnt++;
			if (s[l]>s[r]) cnt--;
			swap(s[l],s[r]);
			ans=min(cnt,ans);
		}
		cout<<ans<<endl;
	}
}
			
