#include<bits/stdc++.h>
using namespace std;

struct lsh
{
    long long raw[200050];
    long long num,nm;
    lsh(){num=nm=0;}
    void init(){num=nm=0;}
    void add(long long x) {raw[++num]=x;}
    void ready() {sort(raw+1,raw+num+1);nm=unique(raw+1,raw+num+1)-raw-1;}
    long long get(long long x) {return lower_bound(raw+1,raw+nm+1,x)-raw;}
    long long rev(long long x) {return raw[x];}
};

struct BIT_rmq
{
    long long a[200050];
    long long c[400050];
    long long n;
    inline long long lowbit(long long x) {return x&(-x);}
    void init() {memset(c,0,sizeof(c));n=0;}
    void append(long long x)
    {
        a[++n]=x;
        ins(n);
    }
    void ins(long long x)
    {
        c[x]=a[x];
        for (long long i=1;i<lowbit(x);i<<=1)
            c[x]=max(c[x],c[x-i]);
    }
    long long rmq(long long l,long long r)
    {
        long long maxv=a[r];
        while (l<=r)
        {
            maxv=max(maxv,a[r]);
            for (--r;r-l>=lowbit(r);r-=lowbit(r))
                maxv=max(maxv,a[r]);
        }
        return maxv;
    }
};

struct BIT_rmq_postfix
{
    long long c[400050];
    void init() {memset(c,0,sizeof(c));}
    inline long long lowbit(long long x) {return x&(-x);}
    void modify(long long pos,long long val)
    {
        for (;pos;pos-=lowbit(pos)) c[pos]=max(c[pos],val);
    }
    long long get(long long pos)
    {
        long long ans=0;
        for (;pos<400050;pos+=lowbit(pos))
            ans=max(ans,c[pos]);
        return ans;
    }
};
long long a[200050];
long long f[200050];
lsh m_lsh;
BIT_rmq_postfix rmq;
int main()
{
    long long T;
    ios::sync_with_stdio(0);cin.tie(0);
    cin>>T;
    while (T--)
    {
        long long n,k;
        cin>>n>>k;
        for (long long i=1;i<=n;i++)
        {
            cin>>a[i];
            a[i]+=(i==1)?0:a[i-1];
            m_lsh.add(a[i]);
        }
        m_lsh.ready();
        long long l=-1e16,r=1e16,ans=0;
        while (l<=r)
        {
            memset(f,0,sizeof(f));
            rmq.init();
            long long mid=(l+r)>>1;
            long long curmax=0;
            for (int i=1;i<=n;i++)
            {
                long long pos=m_lsh.get(a[i]-mid);
                //cout<<mid<<":"<<pos<<endl;
                if (a[i]<=mid) f[i]=1;
                int tmp=rmq.get(pos);
                if (tmp) f[i]=tmp+1;
                curmax=max(curmax,f[i]);
                rmq.modify(m_lsh.get(a[i]),f[i]);
            }
            if (curmax>=k) {ans=mid;r=mid-1;} else l=mid+1;
        }
        cout<<ans<<endl;
    }
}