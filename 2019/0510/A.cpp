#include<bits/stdc++.h>
using namespace std;
int main()
{
	int k;
	cin>>k;
	string s1,s2;
	cin>>s1>>s2;
	int t=0;
	for (int i=0;i<s1.size();i++)
	{
		if (s1[i]==s2[i]) t++;
	}
	if (t<k) cout<<t+s1.size()-k<<endl;else cout<<k+s1.size()-t<<endl;
	return 0;
}
