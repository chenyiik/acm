#include<bits/stdc++.h>
using namespace std;
struct edget
{
    long long v,w;
};
vector<edget> G[100050];
long long n,t[100050];
long long len[100050],sz[100050],sumt[100050];
void getlen(long long u,long long fa)
{
    sz[u]=1;sumt[u]=t[u];
    for (auto x:G[u])
    {
        long long v,w;
        v=x.v;w=x.w;
        if (v==fa) continue;
        len[v]=len[u]+w;
        getlen(v,u);
        sz[u]+=sz[v];
        sumt[u]+=sumt[v];
    }
}
long long ans[100050];
void solve(long long u,long long fa,long long sumlen,long long tsumlen)
{
    ans[u]=t[u]*sumlen+tsumlen;
    for (auto x:G[u])
    {
        long long v=x.v,w=x.w;
        if (v==fa) continue;
        solve(v,u,sumlen+w*(n-(sz[v]<<1)),tsumlen+w*(sumt[1]-(sumt[v]<<1)));
    }
}
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);
    cin>>n;
    for (long long i=1;i<=n;i++) cin>>t[i];
    for (long long i=1;i<=n-1;i++)
    {
        long long u,v,w;
        cin>>u>>v>>w;
        G[u].push_back({v,w});
        G[v].push_back({u,w});
    }
    getlen(1,-1);
    long long sumlen=0,tsumlen=0;
    for (long long i=1;i<=n;i++)
    {
        sumlen+=len[i];
        tsumlen+=t[i]*len[i];
    }
    solve(1,-1,sumlen,tsumlen);
    for (long long i=1;i<=n;i++) cout<<ans[i]<<endl;
}