#include<bits/stdc++.h>
using namespace std;
using LL=long long;
LL phi(LL n)
{
    LL ans=n;
    for(LL i=2;i*i<=n;i++)
        if(n%i==0)
        {
            ans-=ans/i;
            while(n%i==0) n/=i;
        }
    if(n>1) ans-=ans/n;
    return ans;
}
LL qpow(LL a,LL n,LL m)
{
    LL ans=1;
    bool tag=false;
    while(1)
    {
        if(n&1)
        {
            ans*=a;
            if(ans>=m)
            {
                tag=true;
                ans%=m;
            }
        }
        n>>=1;
        if(n==0) break;
        a=a*a;
        if(a>=m)
        {
            tag=true;
            a%=m;
        }
    }
    return tag ? ans%m+m : ans%m;
}
LL solve(LL l,LL a,LL b,LL m)
{
    if(m==1) return (a<m) ? a%m : a%m+m;
    if(l==b) return (a<m) ? a%m : a%m+m;
    LL p=phi(m);
    return qpow(a,solve(l+1,a,b,p),m);
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    LL T;
    cin>>T;
    while(T--)
    {
        LL a,b,m;
        cin>>a>>b>>m;
        if(b==0)
        {
            cout<<1%m<<endl;
            continue;
        }
        cout<<solve(1,a,b,m)%m<<endl;
    }
}