#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios::sync_with_stdio(0);
	int t;cin>>t;
	while (t--)
	{
		long long n,m;
		cin>>n>>m;
		cout<<(long long)(floor(1.0*sqrt(n))*floor(1.0*sqrt(m)))<<endl;
	}
}
