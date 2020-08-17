#include<bits/stdc++.h>
using namespace std;
int main()
{
	int T;
	cin>>T;
	while (T--)
	{
		int n;
		cin>>n;
		static long long a[22];
		for (int i=1;i<=n;i++) cin>>a[i];
		if (n<2) {cout<<"Yes"<<endl;continue;}
		if (n==2)
		{
			long long xp=a[2]*a[2]-4*a[1]*a[3];
			if (xp<0) {cout<<"Yes"<<endl;continue;}
			else {cout<<"No"<<endl;continue;}
		}
		cout<<"No"<<endl;
	}
	return 0;
}
