#include<bits/stdc++.h>
using namespace std;
int main()
{
	static int a[101],b[101];
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T;
	cin>>T;
	while (T--)
	{
		int n;
		cin>>n;
		for (int i=1;i<=n;i++) cin>>a[i];
		for (int i=1;i<=n;i++) cin>>b[i];
		bool bj=true;
		for (int i=1;i<=n;i++)
		{
			if (a[i]<b[i]) continue;
			int ref=a[i]-b[i];
			for (int tag=i+1;tag<=n;tag++)
			{
				if (b[tag]<ref)
				{
					ref-=b[tag];
					b[tag]=0;
				}
				else
				{
					b[tag]-=ref;
					ref=0;
					break;
				}
			}
			if (ref!=0) {bj=false;cout<<"No"<<endl;break;}
		}
		if (bj) cout<<"Yes"<<endl;
	}
	return 0;
}
