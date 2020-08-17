#include<bits/stdc++.h>
using namespace std;
int main()
{
	int T;
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>T;
	while (T--)
	{
		int n;
		cin>>n;
		static int a[101];
		for (int i=1;i<=n;i++) cin>>a[i];
		int x=3*a[1];
		for (int i=2;i<=n;i++) if (x<(a[i]+1)) x=a[i]+1;
		if (x&1) x++;
		cout<<x<<endl;
	}
	return 0;
}
