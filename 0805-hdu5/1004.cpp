#include<bits/stdc++.h>
using namespace std;
long long a[100005],b[100005];
struct ln
{
    double pt;
    long long num;
    bool operator <(const ln& b) const
    {
        return pt<b.pt;
    }
};
ln d[100005];
long long mp[100005];
long long sumk=0,sumb=0;
long long gcd(long long a,long long b)
{
    if (b==0) return a;
    return gcd(b,a%b);
}
struct frac
{
    long long up,down;
    long long fh=0;
    frac(long long _up=0,long long _down=0) {up=_up,down=_down;}
    void formula()
    {
        if (down<0) up=-up,down=-down;
        if (up==0) {down=1;return;}
        long long x=gcd(abs(up),down);
        up/=x,down/=x;
    }
};
vector<frac> ans;
int main()
{
    long long T;
    scanf("%d",&T);
    while (T--)
    {
        long long n,c;
        ans.clear();
        scanf("%lld%lld",&n,&c);
        long long sumk=0,sumb=0;
        for (long long i=1;i<=n;i++) scanf("%lld %lld",&a[i],&b[i]),sumk-=a[i],sumb-=b[i];
        for (long long i=1;i<=n;i++) d[i].pt=-(double(b[i])/double(a[i])),d[i].num=i;
        d[0].pt=-(1e9);d[n+1].pt=1e9;
        sort(d+1,d+n+2);
        bool hasans=false,infans=false;
        double l=d[0].pt,r=d[1].pt;
        for (long long i=1;i<=n+1;i++)
        {
            if (sumk==0 && sumb==c) {printf("-1\n");hasans=false;infans=true;break;}
            if (sumk==0 && sumb!=c) {continue;}
            double x=(double(c)-double(sumb))/double(sumk);
            if (x>=l && x<r)
            {
                hasans=true;
                frac tmp=frac(c-sumb,sumk);
                ans.push_back(tmp);
            }
            l=d[i].pt,r=d[i+1].pt;
            sumk+=2*a[d[i].num];sumb+=2*b[d[i].num];
        }
        if (infans) continue;
        if (!hasans) {printf("0\n");continue;}
        printf("%d ",ans.size());
        for (int i=0;i<ans.size()-1;i++) {ans[i].formula();printf("%lld/%lld ",ans[i].up,ans[i].down);}
        ans[ans.size()-1].formula();printf("%lld/%lld",ans[ans.size()-1].up,ans[ans.size()-1].down);
        puts("");
    }
}