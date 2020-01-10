#include<bits/stdc++.h>
using namespace std;
long long a[100050];
long long b[100050];
long long cnt[100050];
int main()
{
	int T;
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>T;
	while(T--)
	{
		long long n,x,y;
		cin>>n>>x>>y;
		long long curx=0,cury=0;
		for (int i=1;i<=n;i++) 
		{cin>>a[i];b[i-1]=a[i];cnt[i-1]=0;curx+=(i*a[i]);cury+=(i*a[i]*a[i]);}
		long long diffx=x-curx,diffy=y-cury;
		if (diffx==0 && diffy!=0) {cout<<0<<endl;continue;}
		if (diffx==0 && diffy==0)
		{
			long long ans=0;
			sort(b,b+n);
			int m=unique(b,b+n)-b;
			for(int i=1;i<=n;i++)
				cnt[lower_bound(b,b+m,a[i])-b]++;
			for(int i=0;i<m;i++)
				ans+=1LL*cnt[i]*(cnt[i]-1)/2;
			cout<<ans<<endl;
			continue;
		}
		if (abs(diffy)%abs(diffx)!=0) {cout<<0<<endl;continue;}
		long long rough=diffy/diffx;
		long long ans=0;
		for (long long i=1;i<=n;i++)
		{
			long long fm=rough-2*a[i];
			if(fm==0)continue;
			long long fs=diffx/fm;
			if (abs(diffx)%abs(fm)!=0) continue;
			long long j=i-fs;
			if (j<=n && j>=1)
			if (a[j]+a[i]==rough) ans++;
		}
		cout<<ans/2<<endl;
	}
	return 0;
}
