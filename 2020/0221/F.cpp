#include<bits/stdc++.h>
using namespace std;
vector<int> G[1000050];
int f[1000050],vis[1000050];
void solve(int u,int from)
{
    f[u]=-1;
    bool succ=false;
    for (auto x:G[u])
    {
        if (x==from) continue;
        solve(x,u);
        if (vis[x]) succ=true;
        f[u]+=max(f[x],vis[x]);
    }
    if (!succ||f[u]>0) vis[u]=1;
}
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);
    int n;
    cin>>n;
    for (int i=1;i<n;i++)
    {
        int u,v;
        cin>>u>>v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    solve(1,0);
    cout<<(f[1]?"Alice":"Bob")<<endl;
}