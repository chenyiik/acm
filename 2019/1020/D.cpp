#include<bits/stdc++.h>
using namespace std;
int n,k;
vector<int> G[100050];
vector<int> L[100050];
int linklen[100050];
void dfs(int u)
{
    if (G[u].size()==0)
    {
        linklen[u]=1;
        return;
    }
    int mxl=0,mxp=0;
    for (auto x:G[u])
    {
        dfs(x);
        if (linklen[x]>mxl)
        {
            mxl=linklen[x];
            mxp=x;
        }
    }
    linklen[u]=mxl+1;
    for (auto x:G[u])
    {
        if (x!=mxp)
        {
            L[u].push_back(x);
        }
    }
    for (auto x:L[mxp])
        L[u].push_back(x);
}
struct node
{
    int v,w;
    bool operator<(const node& b) const
    {
        return w<b.w;
    }
};
priority_queue<node> pq;
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);
    cin>>n>>k;
    for (int i=2;i<=n;i++)
    {
        int v;
        cin>>v;
        G[v].emplace_back(i);
    }
    dfs(1);
    pq.push(node{1,linklen[1]});
    long long ans=0;
    while (!pq.empty() && k>0)
    {
        auto nd=pq.top();pq.pop();
        auto v=nd.v,w=nd.w;
        ans+=w;
        for (auto vv:L[v])
            pq.push(node{vv,linklen[vv]});
        k--;
    }
    cout<<ans<<endl;
}