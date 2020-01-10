#include<bits/stdc++.h>
using namespace std;
int n,m,k;
struct lsh
{
    int raw[200050];
    int num=0,nm=0;
    void add(int x) {raw[++num]=x;}
    void ready() {sort(raw+1,raw+num+1);nm=unique(raw+1,raw+num+1)-raw-1;}
    int get(int x) {return lower_bound(raw+1,raw+nm+1,x)-raw;}
    int getunique(){return nm;}
};
struct BIT
{
    int sum1[200050],sum2[200050];
    int lowbit(int x) {return x&(-x);}
    void init()
    {
        memset(sum1,0,sizeof(sum1));
        memset(sum2,0,sizeof(sum1));
    }
    void add(int p,int x)
    {
        for (int i=p;i<=200050;i+=lowbit(i)) sum1[i]+=x,sum2[i]+=x*p;
    }
    void rangeadd(int l,int r,int x)
    {
        add(l,x);
        add(r+1,-x);
    }
    int query(int p)
    {
        int res=0;
        for (int i=p;i;i-=lowbit(i))
            res+=(p+1)*sum1[i]-sum2[i];
        return res;
    }
    int rangequery(int l,int r)
    {
        return query(r)-query(l-1);
    }
};
struct line
{
    int x,y;
    char dir;
    bool operator <(const line& b) const
    {
        return y<b.y;
    }
};
line L[100050];
lsh x_lsh;
BIT rg;
int main()
{
    int T;
    ios::sync_with_stdio(0);cin.tie(0);
    cin>>T;
    while (T--)
    {
        x_lsh.num=0;x_lsh.nm=0;
        cin>>n>>m>>k;
        rg.init();
        for (int i=1;i<=k;i++)
        {
            int x,y;string p;
            cin>>x>>y>>p;
            x_lsh.add(x);
            L[i].x=x,L[i].y=y,L[i].dir=p[0];
        }
        x_lsh.ready();
        for (int i=1;i<=k;i++) L[i].x=x_lsh.get(L[i].x);
        sort(L+1,L+k+1);
        int ans=1;
        for (int i=1;i<=k;i++)
        {
            if (L[i].dir=='L') rg.rangeadd(1,L[i].x,1);
            if (L[i].dir=='R') rg.rangeadd(L[i].x,x_lsh.nm,1);
            if (L[i].dir=='D') ans+=rg.rangequery(L[i].x,L[i].x);
        }
        rg.init();
        for (int i=k;i>=1;i--)
        {
            if (L[i].dir=='L') rg.rangeadd(1,L[i].x,1);
            if (L[i].dir=='R') rg.rangeadd(L[i].x,x_lsh.nm,1);
            if (L[i].dir=='U') ans+=rg.rangequery(L[i].x,L[i].x);
        }
        cout<<ans<<endl;
    }
<<<<<<< HEAD
}
=======
}
>>>>>>> c60af5c3ebf4bc0dfa120787215675ab9379400c
