#include<bits/stdc++.h>
using namespace std;
const long long modl= (long long)(1e9+7);
long long qpow(long long a,long long n)
{
    if (!n) return 1;
    long long ans=qpow(a,n>>1)%modl;
    ans=ans*ans%modl;
    if (n&1)
        ans=ans*a%modl;
    return ans;
}
int main()
{
    long long n;
    while (cin>>n)
        cout<<(n+1)*qpow(2*n,modl-2)%modl<<endl;
}