#include<bits/stdc++.h>
using namespace std;
const long long modl=1000003;
long long frac[modl+50]; 
int main()
{
    long long n;
    frac[0]=1;
    for (long long i=1;i<=modl+1;i++) frac[i]=frac[i-1]*i%modl;
	while (cin>>n) if (n>modl) cout<<0<<endl;else cout<<frac[n]%modl<<endl;
	return 0;
}
