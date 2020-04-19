#include<bits/stdc++.h>
using namespace std;
long long token[25],b=0;
long long w1(long long p)
{
    long long ans=10;
    for (long long i=0;i<p-2;i++) ans*=10;
    return p*(p-1)/2*9*ans/2;
}
long long w2(long long p)
{
    long long ans=1;
    for (long long i=0;i<p;i++) ans*=10;
    return ans/10*p;
}
long long ws(long long n,long long p)
{
    long long r=0,k=0,q=1;
    for (long long i=1;i<=p;i++)
    {
        r+=token[i]>n?k+1:0;
        r+=(token[i]>n?token[i]-n-1:0)*q;
        r+=token[i]*(9-n)*w2(i-1);
        k=k+token[i]*q;q*=10;
    }
    return r;
}
long long calc(long long v)
{   
    b=0;
    while (v) token[++b]=v%10,v/=10;
    long long ans=0;
    for (long long i=b;i;i--)
    {
        ans+=token[i]*w1(i-1);
        ans+=(9*token[i]-(token[i]*(token[i]-1))/2)*w2(i-1);
        ans+=ws(token[i],i-1);
    }
    for (long long i=1;i<b;i++) ans-=9*w2(i);
    return ans;
}
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);
    long long t;cin>>t;
    while (t--)
    {
        static long long cas=0;
        cout<<"Case "<<++cas<<": ";
        long long x,y;cin>>x>>y;
        cout<<calc(y)-calc(x-1)<<endl;
    }
}