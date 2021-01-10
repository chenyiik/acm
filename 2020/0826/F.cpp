<<<<<<< HEAD
#include<vector>
#include<iomanip>
#include<iostream>
using namespace std;
const long long modl=1e9+7;
long long fa[100050];
long long num0[100050],num1[100050];
long long a[100050];
vector<pair<long long,long long>> G[100050];
long long getfa(long long x)
{
    if (fa[x]==x) return x;
    fa[x]=getfa(fa[x]);
}
void dfs(long long u,long long f)
{
    num0[u]+=(a[u]==0);
    num1[u]+=(a[u]==1);
    for (auto x:G[u])
    {
        if (x.first==f) continue;
        dfs(x.first,u);
        num0[u]+=num0[x.first];
        num1[u]+=num1[x.first];
    }
}
long long n,m,sum0=0,sum1=0,ans=0;
void solve(long long u,long long f)
{
    for (auto x:G[u])
    {
        if (x.first==f) continue;
        long long c0=sum0-num0[x.first],c1=sum1-num1[x.first];
        ans=(ans+x.second%modl*(c0%modl*num1[x.first]%modl+c1%modl*num0[x.first]%modl)%modl)%modl;
        solve(x.first,u);
    }
}
void doo()
{
    cin>>n>>m;
    ans=0;sum0=0;sum1=0;
    for (long long i=1;i<=n;i++)
    {
        cin>>a[i];fa[i]=i;
        sum0+=(a[i]==0);
        sum1+=(a[i]==1);
        G[i].clear();G[i].shrink_to_fit();
        num0[i]=num1[i]=0;
    }
    long long xp=1;
    for (long long i=1;i<=m;i++)
    {
        long long u,v;
        xp=(xp<<1)%modl;
        cin>>u>>v;
        long long fu=getfa(u),fv=getfa(v);
        if (fu==fv) continue;
        fa[fu]=fv;
        G[u].push_back({v,xp});
        G[v].push_back({u,xp});
    }
    dfs(1,0);
    solve(1,0);
    cout<<ans<<endl;
}
signed main()
{
    ios::sync_with_stdio(0);
    long long t;cin>>t;
    while (t--) doo();
}
=======
#include<vector>
#include<iomanip>
#include<iostream>
using namespace std;
const long long modl=1e9+7;
long long fa[100050];
long long num0[100050],num1[100050];
long long a[100050];
vector<pair<long long,long long>> G[100050];
long long getfa(long long x)
{
    if (fa[x]==x) return x;
    fa[x]=getfa(fa[x]);
}
void dfs(long long u,long long f)
{
    num0[u]+=(a[u]==0);
    num1[u]+=(a[u]==1);
    for (auto x:G[u])
    {
        if (x.first==f) continue;
        dfs(x.first,u);
        num0[u]+=num0[x.first];
        num1[u]+=num1[x.first];
    }
}
long long n,m,sum0=0,sum1=0,ans=0;
void solve(long long u,long long f)
{
    for (auto x:G[u])
    {
        if (x.first==f) continue;
        long long c0=sum0-num0[x.first],c1=sum1-num1[x.first];
        ans=(ans+x.second%modl*(c0%modl*num1[x.first]%modl+c1%modl*num0[x.first]%modl)%modl)%modl;
        solve(x.first,u);
    }
}
void doo()
{
    cin>>n>>m;
    ans=0;sum0=0;sum1=0;
    for (long long i=1;i<=n;i++)
    {
        cin>>a[i];fa[i]=i;
        sum0+=(a[i]==0);
        sum1+=(a[i]==1);
        G[i].clear();G[i].shrink_to_fit();
        num0[i]=num1[i]=0;
    }
    long long xp=1;
    for (long long i=1;i<=m;i++)
    {
        long long u,v;
        xp=(xp<<1)%modl;
        cin>>u>>v;
        long long fu=getfa(u),fv=getfa(v);
        if (fu==fv) continue;
        fa[fu]=fv;
        G[u].push_back({v,xp});
        G[v].push_back({u,xp});
    }
    dfs(1,0);
    solve(1,0);
    cout<<ans<<endl;
}
signed main()
{
    ios::sync_with_stdio(0);
    long long t;cin>>t;
    while (t--) doo();
}
>>>>>>> 323e5ad27149b03367cf5d310ddce65fdf1b9973
