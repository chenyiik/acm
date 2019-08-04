#include<bits/stdc++.h>
using namespace std;
long long qpow(long long a,long long b,long long p)
{
    long long ans=1;
    for (;b;b>>=1,a=(a*a)%p) {ans*=(b&1)?a:1;ans%=p;}
    return ans;
}
int main()
{
    long long T;
    cin>>T;
    while (T--)
    {
        long long p,n,m;
        cin>>p>>n>>m;
        if (p==3) {cout<<(n/3)*m<<endl;continue;}
        if (p==2||p==5) {cout<<0<<endl;continue;}
        long long d=-1,x=p-1;
        for (long long i=1;i*i<=x;i++)
            if (!(x%i))
            {
                if (qpow(10,i,p)==1) {d=i;break;}
                if (i*i!=x && qpow(10,x/i,p)==1) d=x/i;
            }
        if (d==-1) {cout<<0<<endl;continue;}
        long long fac[110],cnt[110],c=0;
        memset(cnt,0,sizeof(cnt));
        memset(fac,0,sizeof(fac));
        c=0;
        for (long long i=2;i*i<=d;i++)
        if (!(d%i))
        {
            fac[++c]=i;
            for(;!(d%i);d/=i) cnt[c]++;
        }
        if (d!=1) fac[++c]=d,cnt[c]=1;
        long long ans=0;
        long long g[35];
        memset(g,0,sizeof(g));
        for (long long j=1;j<=min(m,30LL);j++)
        {
            g[j]=1;
            for (long long x=1;x<=c;x++) g[j]*=qpow(fac[x],(cnt[x]%j==0)?cnt[x]/j:cnt[x]/j+1,p);
            ans+=n/g[j];
        }
        if (m>30) ans+=(m-30)*(n/g[30]);
        cout<<ans<<endl;
    }
    return 0;
}