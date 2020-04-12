#include<bits/stdc++.h>
using namespace std;
long long n,m;
vector<long long> G[100050];
long long la[100050],lb[100050],ca[100050],cb[100050];
void dfs(long long u,long long f,long long len[],bool sec=0)
{
    if (G[u].size()==1)
    {
        len[u]=0;
        if (u!=f) return;
    }
    if (sec) len[u]=min(len[u],len[f]+1);
    for (auto x:G[u])
        if (x!=f)
        {
            dfs(x,u,len,sec);
            if (!sec) len[u]=min(len[u],len[x]+1);
        }
}
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);
    cin>>n;
    if (n==2) {cout<<"0.000000000000"<<endl;return 0;}
    for (long long i=1;i<=n-1;i++)
    {
        long long u,v;
        cin>>u>>v;
        G[u].push_back(v);
        G[v].push_back(u);
        la[i+1]=la[i]=n;
    }
    dfs(1,1,la);dfs(1,1,la,1);
    for (long long i=1;i<=n;i++) ca[la[i]]++;
    for (long long i=n;i>=1;i--) ca[i]+=ca[i+1];
    cin>>m;
    if (m==2) {cout<<"0.000000000000"<<endl;return 0;}
    for (long long i=1;i<=m;i++) G[i].clear();
    for (long long i=1;i<=m-1;i++)
    {
        long long u,v;
        cin>>u>>v;
        G[u].push_back(v);
        G[v].push_back(u);
        lb[i+1]=lb[i]=m;
    }
    dfs(1,1,lb);dfs(1,1,lb,1);
    for (long long i=1;i<=m;i++) cb[lb[i]]++;
    for (long long i=m;i>=1;i--) cb[i]+=cb[i+1];
    double ans=0;
    for (long long i=1;i<=min(n,m)-1;i++)
        ans+=double(ca[i]*cb[i])/double(n*m);
    cout.setf(ios::fixed);
    cout.precision(12);
    cout<<ans<<endl;
}