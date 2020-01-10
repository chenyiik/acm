#include<bits/stdc++.h>
using namespace std;
const long long modd=(long long)(1e9)+7LL;
long long powmod(long long a,long long n,long long mod)
{
    long long ret=1;
    long long tmp=a%mod;
    while (n)
    {
        if (n&1) ret=(ret*tmp)%mod;
        tmp=(tmp*tmp)%mod;
        n>>=1;
    }
    return ret;
}
long long inv(long long a,long long mod)
{
    return powmod(a,mod-2,mod);
}
inline long long solve(double f[][75],bool l[],long long p[],const long long& n)
{
    long long res=0,r=0;
    for (long long i=0;i<n;i++) l[i]=false;
    for (long long i=0;i<n;i++)
    {
        for (long long j=r;j<n;j++)
            if (fabs(f[j][i])>1e-8)
            {
                for(long long k=i;k<=n;k++) swap(f[j][k],f[r][k]);
                break;
            }
        if (fabs(f[r][i])<1e-8)
        {
            ++res;
            continue;
        }
        for (long long j=0;j<n;j++)
            if (j!=r && fabs(f[j][i])>1e-8)
            {
                double tmp=f[j][i]/f[r][i];
                for (long long k=i;k<=n;k++)
                    f[j][k]-=tmp*f[r][k];
            }
        l[i]=true;++r;
    }
    for (long long i=0;i<n;i++)
        if (l[i])
            for (long long j=0;j<n;j++)
                if (fabs(f[j][i])>0)
                    p[i]=f[j][n]*inv(f[j][i],(long long)(1e9)+7LL);
    return res;
}
struct mat
{
    long long n,m;
    long long a[75][75];
    void clear() {memset(a,0,sizeof(a));n=m=0;}
    mat operator* (const mat& b) const
    {
        mat tmp;
        tmp.clear();
        tmp.n=n;tmp.m=b.m;
        for (int i=0;i<n;i++)
            for (int j=0;j<b.m;j++)
                for (int k=0;k<m;k++)
                {
                    tmp.a[i][j]+=a[i][k]*b.a[k][j];
                    tmp.a[i][j]%=modd;
                }
        return tmp;
    }
};
mat powmat(mat a,long long n,long long mod)
{
    mat ret;ret.clear();
    ret.n=a.n,ret.m=a.m;
    for (int i=0;i<ret.n;i++) ret.a[i][i]=1;
    mat tmp=a;
    while (n)
    {
        if (n&1) ret=ret*tmp;
        tmp=tmp*tmp;
        n>>=1;
    }
    return ret;
}

long long f[405];
double a[75][75];
int main()
{
    long long t;
    cin>>t;
    while (t--)
    {
        long long n,k;
        cin>>k>>n;
        memset(f,0,sizeof(f));
        memset(a,0,sizeof(a));
        for (long long i=1;i<=k+k;i++) cin>>f[i];
        if (n<=k)
        {
            cout<<f[n]<<endl;continue;
        }
        long long l1=0;
        for (long long i=0;i<=k;i++) a[0][i]=1;
        for (long long i=1;i<=k;i++)
        {
            a[i][k]=f[i+k];
            for(long long j=0;j<=k-1;j++) a[i][j]=f[i+k-j-1];
        }
        long long p[75];
        bool l[75];
        long long t=solve(a,l,p,k);
        mat rt;rt.clear();
        rt.n=rt.m=k+1;
        for (int i=0;i<=k-2;i++)
            rt.a[i+1][i]=1;
        for (int i=0;i<k;i++)
            rt.a[i][k-1]=rt.a[i][k]=p[k-i-1];
        rt.a[k][k]=1;
        mat rtt=powmat(rt,n-k,modd);
        mat lt;lt.clear();
        lt.n=1;lt.m=k+1;
        for (int i=0;i<k;i++) lt.a[0][k]+=lt.a[0][i]=f[i+1];
        mat ans;ans.clear();ans=lt*rtt;
        cout<<ans.a[0][k]<<endl;
    }
    return 0;
}